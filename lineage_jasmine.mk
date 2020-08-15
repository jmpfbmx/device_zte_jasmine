#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Device
$(call inherit-product, device/zte/jasmine/full_jasmine.mk)

# Device identifier. This must come after all inclusions
TARGET_VENDOR := zte
PRODUCT_DEVICE := jasmine
PRODUCT_NAME := lineage_jasmine
PRODUCT_BRAND := zte
PRODUCT_MODEL := K88
PRODUCT_MANUFACTURER := zte
BOARD_VENDOR := zte

PRODUCT_GMS_CLIENTID_BASE := android-zte

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_DEVICE="jasmine" \
    PRODUCT_NAME="K88" \
    PRIVATE_BUILD_DESC="K88-user 7.1.1 NMF26V 20170828.115541 release-keys"

BUILD_FINGERPRINT := ZTE/K88/jasmine:7.1.1/NMF26V/20170828.115541:user/release-keys
