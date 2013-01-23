LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# not compile corefundation library for android.
#$(LOCAL_PATH)/../corefoundation-lite-android/Android.mk 

subdirs := $(LOCAL_PATH)/ejecta/Android.mk \
           $(LOCAL_PATH)/platform_external_icu4c/Android.mk \
           $(LOCAL_PATH)/Source/JavaScriptCore/cutils/Android.mk \
           $(LOCAL_PATH)/Android_ejecta.mk \
           $(LOCAL_PATH)/libpng/Android.mk \
           $(LOCAL_PATH)/libjpeg/Android.mk \

include $(subdirs)
