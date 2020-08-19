/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "light"

#include "Light.h"

#include <log/log.h>

namespace {
using android::hardware::light::V2_0::LightState;

static const char* const lcd_backlight_filename =
    "/sys/class/leds/lcd-backlight/brightness";

static void
write_file(const char *path, const char *str)
{
    int fd;
    ssize_t written = -1;

    ALOGI("%s: path=%s str=%s\n", __func__, path, str);
    fd = open(path, O_RDWR);
    if (fd < 0) {
        ALOGE("%s: Failed to open %s: %s\n",
                __func__, path, strerror(errno));
        return;
    }
    written = write(fd, str, strlen(str));
    if (written < 0) {
        ALOGE("%s: Failed to write to %s: %s\n",
                __func__, path, strerror(errno));
    }
    close(fd);
}

static uint32_t rgbToBrightness(const LightState& state) {
    uint32_t color = state.color & 0x00ffffff;
    return ((77 * ((color >> 16) & 0xff)) + (150 * ((color >> 8) & 0xff)) +
            (29 * (color & 0xff))) >> 8;
}

} // anonymous namespace

namespace android {
namespace hardware {
namespace light {
namespace V2_0 {
namespace implementation {

static constexpr uint32_t MODE_ON = 0x1;
static constexpr uint32_t MODE_BLINK = 0x2;

static constexpr uint32_t MODE_SHIFT = 24;
static constexpr uint32_t MODE_MASK = 0x0f000000;

Light::Light()
{
    auto backlightFn(std::bind(&Light::setBacklight, this, std::placeholders::_1));
    mLights.emplace(std::make_pair(Type::BACKLIGHT, backlightFn));
}

// Methods from ::android::hardware::light::V2_0::ILight follow.
Return<Status> Light::setLight(Type type, const LightState& state) {
    auto it = mLights.find(type);

    if (it == mLights.end()) {
        return Status::LIGHT_NOT_SUPPORTED;
    }

    it->second(state);

    return Status::SUCCESS;
}

Return<void> Light::getSupportedTypes(getSupportedTypes_cb _hidl_cb) {
    std::vector<Type> types;

    for (auto const& light : mLights) {
        types.push_back(light.first);
    }

    _hidl_cb(types);

    return Void();
}

void Light::setBacklight(const LightState& state) {
    std::lock_guard<std::mutex> lock(mLock);

    char val[12+1];
    snprintf(val, sizeof(val), "%u", rgbToBrightness(state));
    write_file(lcd_backlight_filename, val);
}

} // namespace implementation
}  // namespace V2_0
}  // namespace light
}  // namespace hardware
}  // namespace android
