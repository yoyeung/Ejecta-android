#
# Copyright (C) 2008 The Android Open Source Project
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
LOCAL_PATH := $(my-dir)
include $(CLEAR_VARS)

targetSmpFlag := -DANDROID_SMP=0

hostSmpFlag := -DANDROID_SMP=0

commonSources := \
	array.c \
	hashmap.c \
	atomic.c.arm \
	native_handle.c \
	buffer.c \
	socket_inaddr_any_server.c \
	socket_local_client.c \
	socket_local_server.c \
	socket_loopback_client.c \
	socket_loopback_server.c \
	socket_network_client.c \
	sockets.c \
	config_utils.c \
	cpu_info.c \
	load_file.c \
	list.c \
	open_memstream.c \
	strdup16to8.c \
	strdup8to16.c \
	record_stream.c \
	process_name.c \
	properties.c \
	threads.c \
	sched_policy.c \
	iosched_policy.c \
	str_parms.c

commonHostSources := \
        ashmem-host.c

# some files must not be compiled when building against Mingw
# they correspond to features not used by our host development tools
# which are also hard or even impossible to port to native Win32
WINDOWS_HOST_ONLY :=
ifeq ($(HOST_OS),windows)
    ifeq ($(strip $(USE_CYGWIN)),)
        WINDOWS_HOST_ONLY := 1
    endif
endif
# USE_MINGW is defined when we build against Mingw on Linux
ifneq ($(strip $(USE_MINGW)),)
    WINDOWS_HOST_ONLY := 1
endif

# ifeq ($(WINDOWS_HOST_ONLY),1)
# Walzer marked, restrict to WINDOWS_HOST_ONLY, otherwise mspace.c will failed
    commonSources += \
        uio.c
# else
#    commonSources += \
#        abort_socket.c \
#        mspace.c \
#        selector.c \
#        tztime.c \
#        zygote.c

#    commonHostSources += \
#        tzstrftime.c
# endif


# Static library for host
# ========================================================
LOCAL_MODULE := libcutils
LOCAL_C_INCLUDES := $(LOCAL_C_INCLUDES) \
    $(LOCAL_PATH)/..
    
LOCAL_SRC_FILES := $(commonSources) $(commonHostSources) dlmalloc_stubs.c
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS += $(hostSmpFlag) -DHAVE_PTHREADS
include $(BUILD_STATIC_LIBRARY)
