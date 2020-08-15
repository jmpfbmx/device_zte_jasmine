LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
  gps_shim.cpp

LOCAL_MODULE := libshim_gps
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := atomic.cpp
LOCAL_MODULE := libshim_atomic
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := camera.cpp
LOCAL_SHARED_LIBRARIES := libui libutils
LOCAL_MODULE := libshim_camera
LOCAL_MODULE_TAGS := optional
LOCAL_MULTILIB := 32
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := bionic/pthread_cond_timedwait.cpp
LOCAL_SHARED_LIBRARIES := libc
LOCAL_MODULE := libshims_qcamera-daemon
LOCAL_MODULE_TAGS := optional
LOCAL_VENDOR_MODULE := true
#LOCAL_32_BIT_ONLY := true
LOCAL_CXX_STL := none
LOCAL_CFLAGS := -O0
LOCAL_SANITIZE := never
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

include $(BUILD_SHARED_LIBRARY)
