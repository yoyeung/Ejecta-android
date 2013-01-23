BASE_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Define our compiler flags
LOCAL_CFLAGS += -Wno-endif-labels -Wno-import -Wno-format
LOCAL_CFLAGS += -fno-strict-aliasing
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DALWAYS_INLINE=inline
LOCAL_CPPFLAGS := -Wno-sign-promo

JAVASCRIPT_ENGINE := false
# Enable JSC JIT if JSC is used and ENABLE_JSC_JIT environment
# variable is set to true
ifeq ($(JAVASCRIPT_ENGINE),jsc)
ifeq ($(ENABLE_JSC_JIT),true)
LOCAL_CFLAGS += -DENABLE_ANDROID_JSC_JIT=1
endif
endif

ifeq ($(TARGET_ARCH),arm)
LOCAL_CFLAGS += -Darm
# remove this warning: "note: the mangling of 'va_list' has changed in GCC 4.4"
LOCAL_CFLAGS += -Wno-psabi
endif

# need a flag to tell the C side when we're on devices with large memory
# budgets (i.e. larger than the low-end devices that initially shipped)
ifeq ($(ARCH_ARM_HAVE_VFP),true)
LOCAL_CFLAGS += -DANDROID_LARGE_MEMORY_DEVICE
endif

ifeq ($(ENABLE_WTF_USE_ACCELERATED_COMPOSITING),false)
LOCAL_CFLAGS += -DWTF_USE_ACCELERATED_COMPOSITING=0
endif

ifeq ($(ENABLE_WTF_USE_ACCELERATED_COMPOSITING),true)
LOCAL_CFLAGS += -DWTF_USE_ACCELERATED_COMPOSITING=1
endif


LOCAL_CFLAGS += -DENABLE_SINGLE_THREADED=1 -D__LINUX__=1 -DCOMPATIBLE_GCC4=1 -D__LITTLE_ENDIAN__=1


JAVASCRIPTCORE_PATH := $(BASE_PATH)/Source/JavaScriptCore

LOCAL_C_INCLUDES := $(LOCAL_C_INCLUDES) \
    $(JAVASCRIPTCORE_PATH)/.. \
	$(JAVASCRIPTCORE_PATH) \
	$(JAVASCRIPTCORE_PATH)/include \
	$(JAVASCRIPTCORE_PATH)/cutils \
	$(JAVASCRIPTCORE_PATH)/API \
	$(JAVASCRIPTCORE_PATH)/assembler \
	$(JAVASCRIPTCORE_PATH)/bytecode \
	$(JAVASCRIPTCORE_PATH)/bytecompiler \
	$(JAVASCRIPTCORE_PATH)/debugger \
	$(JAVASCRIPTCORE_PATH)/collector/handles \
	$(JAVASCRIPTCORE_PATH)/heap \
	$(JAVASCRIPTCORE_PATH)/wtf \
	$(JAVASCRIPTCORE_PATH)/wtf/unicode \
	$(JAVASCRIPTCORE_PATH)/wtf/unicode/icu \
	$(BASE_PATH)/platform_external_icu4c/common \
	$(BASE_PATH)/platform_external_icu4c/i18n \
	$(BASE_PATH)/corefoundation-lite-android \
	$(JAVASCRIPTCORE_PATH)/parser \
	$(JAVASCRIPTCORE_PATH)/interpreter \
	$(JAVASCRIPTCORE_PATH)/jit \
	$(JAVASCRIPTCORE_PATH)/profiler \
	$(JAVASCRIPTCORE_PATH)/runtime 
	
# Now build libjs as a static library.

LOCAL_MODULE := libJavaScriptCore

# Include source files for JavaScriptCore
d := Source/JavaScriptCore
LOCAL_PATH := $(BASE_PATH)/$d

# Cannot use base_intermediates as this is a new module
intermediates := $(call local-intermediates-dir)
include $(LOCAL_PATH)/Android.mk

# Redefine LOCAL_SRC_FILES with the correct prefix
LOCAL_SRC_FILES := $(addprefix $d/,$(LOCAL_SRC_FILES))
# Use the base path to resolve file names
LOCAL_PATH := $(BASE_PATH)
# Append jsc intermediate include paths to the WebKit include list.
LOCAL_C_INCLUDES := $(LOCAL_C_INCLUDES) \
	$(intermediates) \
	$(intermediates)/parser \
	$(intermediates)/runtime \
	
# Build libjs
LOCAL_STATIC_LIBRARIES := libicui18n libicuuc libcutils
LOCAL_SHARED_LIBRARIES := libcorefoundation
include $(BUILD_SHARED_LIBRARY)
