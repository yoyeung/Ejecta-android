/*
 *  CFNetworkCoreTypes.h
 *  CFNetwork
 *
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef __CFNETWORKCORETYPES__
#define __CFNETWORKCORETYPES__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

// forward declarations of core types
typedef const	struct _CFURLRequest*					CFURLRequestRef;
typedef const	struct _CFURLCache*						CFURLCacheRef;
typedef	const	struct __CFURLStorageSession*			CFURLStorageSessionRef;

#endif		// __CFNETWORKCORETYPES__

