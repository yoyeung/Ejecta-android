# Copyright (C) 2009 The Android Open Source Project
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
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ejecta

LOCAL_CFLAGS += -DENABLE_SINGLE_THREADED=1 -DUSE_FILE32API -D__LINUX__=1 -DCOMPATIBLE_GCC4=1 -D__LITTLE_ENDIAN__=1 -DGL_GLEXT_PROTOTYPES=1 -DEJECTA_DEBUG=1

LOCAL_C_INCLUDES := \
                    $(LOCAL_PATH) \
                    $(LOCAL_PATH)/EJAudio \
                    $(LOCAL_PATH)/EJCanvas \
                    $(LOCAL_PATH)/EJCocoa \
                    $(LOCAL_PATH)/EJCocoa/support \
                    $(LOCAL_PATH)/EJUtils \
                    $(LOCAL_PATH)/../libpng/include \
                    $(LOCAL_PATH)/../libjpeg/include \
                    $(LOCAL_PATH)/../Source/JavaScriptCore/include \
                    $(LOCAL_PATH)/../Source/JavaScriptCore/include/JavaScriptCore \
                    $(LOCAL_PATH)/../Source/JavaScriptCore \
                    $(LOCAL_PATH)/../Source/JavaScriptCore/wtf \
                    $(LOCAL_PATH)/../corefoundation-lite-android 

LOCAL_SRC_FILES := \
                    lodepng/lodepng.cpp \
                    EJCocoa/support/nsCArray.cpp \
                    EJCocoa/NSObject.cpp \
                    EJCocoa/NSObjectFactory.cpp \
                    EJCocoa/NSGeometry.cpp \
                    EJCocoa/NSAutoreleasePool.cpp \
                    EJCocoa/NSArray.cpp \
                    EJCocoa/CGAffineTransform.cpp \
                    EJCocoa/NSDictionary.cpp \
                    EJCocoa/NSNS.cpp \
                    EJCocoa/NSSet.cpp \
                    EJCocoa/NSString.cpp \
                    EJCocoa/NSValue.cpp \
                    EJCocoa/NSZone.cpp \
                    EJApp.cpp \
                    EJConvert.cpp \
                    EJBindingBase.cpp \
                    EJBindingEjectaCore.cpp \
                    EJBindingEventedBase.cpp \
                    EJTimer.cpp \
                    EJCanvas/EJBindingImage.cpp \
                    EJCanvas/EJBindingImageData.cpp \
                    EJCanvas/EJBindingCanvas.cpp \
                    EJCanvas/EJCanvasContext.cpp \
                    EJCanvas/EJCanvasContextScreen.cpp \
                    EJCanvas/EJCanvasContextTexture.cpp \
                    EJCanvas/EJPath.cpp \
                    EJCanvas/EJTexture.cpp \
                    EJCanvas/EJImageData.cpp \
                    ejecta.cpp \

LOCAL_LDLIBS :=  -lz -llog -lGLESv1_CM \
                    -L$(LOCAL_PATH)/../libpng/libs/$(TARGET_ARCH_ABI) -lpng \
                    -L$(LOCAL_PATH)/../libjpeg/libs/$(TARGET_ARCH_ABI) -ljpeg \

LOCAL_SHARED_LIBRARIES := libJavaScriptCore libcorefoundation

include $(BUILD_SHARED_LIBRARY)
