LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cpp .cc

include $(CLEAR_VARS)
MAIN_LOCAL_PATH := $(call my-dir)

LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all -llog
LOCAL_ARM_MODE := arm

LOCAL_CPP_FEATURES := exceptions

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

LOCAL_SRC_FILES := main.cpp \
                      sqlite/sqlite3.c

LOCAL_MODULE := rootkiller
LOCAL_C_INCLUDES += $(LOCAL_PATH)/sqlite/sqlite3.c

#LOCAL_LDLIBS := -llog -landroid -lGLESv2 -lz

#LOCAL_STATIC_LIBRARIES := libcurl libssl libcrypto

include $(BUILD_EXECUTABLE)
