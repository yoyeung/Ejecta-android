
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH) $(LOCAL_PATH)/CoreFoundation 
LOCAL_SRC_FILES :=  AppServices.subproj/CFUserNotification.c Base.subproj/CFBase.c Base.subproj/CFFileUtilities.c Base.subproj/CFPlatform.c Base.subproj/CFRuntime.c Base.subproj/CFSortFunctions.c Base.subproj/CFUtilities.c Base.subproj/CFUUID.c Base.subproj/uuid.c Collections.subproj/CFArray.c Collections.subproj/CFBag.c Collections.subproj/CFBinaryHeap.c Collections.subproj/CFBitVector.c Collections.subproj/CFData.c Collections.subproj/CFDictionary.c Collections.subproj/CFSet.c Collections.subproj/CFStorage.c Collections.subproj/CFTree.c NumberDate.subproj/CFDate.c NumberDate.subproj/CFNumber.c NumberDate.subproj/CFTimeZone.c Parsing.subproj/CFBinaryPList.c Parsing.subproj/CFPropertyList.c Parsing.subproj/CFXMLInputStream.c Parsing.subproj/CFXMLNode.c Parsing.subproj/CFXMLParser.c Parsing.subproj/CFXMLTree.c PlugIn.subproj/CFBundle.c PlugIn.subproj/CFBundle_Resources.c PlugIn.subproj/CFPlugIn.c PlugIn.subproj/CFPlugIn_Factory.c PlugIn.subproj/CFPlugIn_Instance.c PlugIn.subproj/CFPlugIn_PlugIn.c String.subproj/CFCharacterSet.c String.subproj/CFString.c String.subproj/CFStringEncodings.c String.subproj/CFStringScanner.c String.subproj/CFStringUtilities.c StringEncodings.subproj/CFBuiltinConverters.c StringEncodings.subproj/CFStringEncodingConverter.c StringEncodings.subproj/CFUniChar.c StringEncodings.subproj/CFUnicodeDecomposition.c StringEncodings.subproj/CFUnicodePrecomposition.c URL.subproj/CFURL.c URL.subproj/CFURLAccess.c version.c

LOCAL_LDLIBS   += -v 
#LOCAL_EXPORT_LDLIBS = -lc

MY_VERSION = 299.33
MY_PLATFORM_CFLAGS = -D__LINUX__=1 -DCOMPATIBLE_GCC4=1 -D__LITTLE_ENDIAN__=1 -DVERSION=$(MY_VERSION)
MY_WARNING_CFLAGS =
LOCAL_CFLAGS = -DCF_BUILDING_CF=1 -g -fno-common -pipe $(MY_PLATFORM_CFLAGS) \
	$(MY_WARNING_CFLAGS) -I. -I./CoreFoundation/

LOCAL_MODULE    := corefoundation

include $(BUILD_SHARED_LIBRARY)

