LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := libfulcrum
LOCAL_SRC_FILES := libfulcrum.c
LOCAL_C_INCLUDES := include
include $(BUILD_STATIC_LIBRARY)
