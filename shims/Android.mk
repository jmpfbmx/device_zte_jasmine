LOCAL_PATH := $(call my-dir)

LOCAL_SRC_FILES := \
  gps_shim.cpp

LOCAL_MODULE := libshim_gps
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
