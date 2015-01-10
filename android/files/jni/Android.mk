LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/../../build-info.mk

LOCAL_CFLAGS    := $(_CFLAGS) $(_ANDROID_CFLAGS)
LOCAL_CPPFLAGS  := $(_CXXFLAGS) $(_ANDROID_CXXFLAGS)
LOCAL_LDLIBS    := $(_ANDROID_LIBS)
LOCAL_MODULE    := $name
LOCAL_SRC_FILES := jni-wrapper.c $(_SOURCES)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/source/
LOCAL_C_INCLUDES += ${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/4.8/include

include $(BUILD_SHARED_LIBRARY)
