/*
 * Copyright (C) 2016 The CyanogenMod Project
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

#include <string>

// status_t android::GgraphicBuffer::reallocate(uint32_t, uint32_t, PixelFormat, uint32_t, uint64_t);
extern "C" int _ZN7android13GraphicBuffer10reallocateEjjijy(unsigned int, unsigned int, int, unsigned int, unsigned long long);

extern "C" int _ZN7android13GraphicBuffer10reallocateEjjij(unsigned int inWidth, unsigned int inHeight, int inFormat, unsigned int inUsage) {
  return _ZN7android13GraphicBuffer10reallocateEjjijy(inWidth, inHeight, inFormat, 1, inUsage);
}
