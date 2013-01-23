/*
	 File:	   CFNetwork/CFURLResponse.h
 
	 Contains:   CFType URL Response header
  
	 Copyright:   Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLRESPONSE__
#define __CFURLRESPONSE__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFHTTPMESSAGE__
#include <CFNetwork/CFHTTPMessage.h>
#endif




#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif


/*
 *  CFURLCacheStoragePolicy
 *  
 *  Discussion:
 *	The CFURLCacheStoragePolicy enum defines constants that can be
 *	used to specify the type of storage that is allowable for an
 *	CFCachedURLResponse object that is to be stored in an CFURLCache.
 *	 This will ultimately live in CFURLCache.h, but for now, we keep
 *	it in CFURLResponse, where it is needed.
 */
enum CFURLCacheStoragePolicy {

  /*
   * Specifies that the response may be stored in a cache without
   * restriction.
   */
  kCFURLCacheStorageAllowed	 = 0,

  /*
   * Specifies that the response may be stored in a cache, but the
   * storage should be in memory only. The response may not be written
   * to disk.
   */
  kCFURLCacheStorageAllowedInMemoryOnly = 1,

  /*
   * Specifies that the response may not be stored in a cache in any
   * fashion.
   */
  kCFURLCacheStorageNotAllowed  = 2
};
typedef enum CFURLCacheStoragePolicy CFURLCacheStoragePolicy;

CFN_EXPORT const SInt64 kCFURLResponseExpectedContentLengthUnknown	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
typedef struct _CFURLResponse*		  CFURLResponseRef;
/*
 *  CFURLResponseGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFURLResponseGetTypeID(void)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLResponseCreate()
 *  
 *  Discussion:
 *	Create a new response
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The allocator to use to create the new object
 *	
 *	URL:
 *	  The URL requested that generated this response; must not be NULL
 *	
 *	mimeType:
 *	  The MIME type of the associated content; may be NULL
 *	
 *	expectedContentLength:
 *	  The expected length of the associated content; use
 *	  kCFURLResponseExpectedContentLengthUnknown if the the length is
 *	  not known.
 *	
 *	textEncodingName:
 *	  If the MIME type is a text type, the name of the expected text
 *	  encoding.  May be NULL.
 *	
 *	recommendedPolicy:
 *	  The cache storage policy recommended for the response
 *  
 *  Result:
 *	The newly created CFURLResponse object
 *  
 */
CFN_EXPORT CFURLResponseRef 
CFURLResponseCreate(
  CFAllocatorRef			alloc,
  CFURLRef				  URL,
  CFStringRef			   mimeType,
  SInt64					expectedContentLength,
  CFStringRef			   textEncodingName,
  CFURLCacheStoragePolicy   recommendedPolicy)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseCreateWithHTTPResponse()
 *  
 *  Discussion:
 *	Create a new response based on an HTTP response; interesting
 *	values like the expected content length, MIME type, etc. will be
 *	automatically calculated from the HTTP headers
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The allocator to use to create the new object
 *	
 *	URL:
 *	  The URL requested that generated this response; must not be NULL
 *	
 *	httpResponse:
 *	  The HTTP response to use
 *	
 *	recommendedPolicy:
 *	  The cache storage policy recommended for the response
 *  
 *  Result:
 *	The newly created CFURLResponse object
 *  
 */
CFN_EXPORT CFURLResponseRef 
CFURLResponseCreateWithHTTPResponse(
  CFAllocatorRef			alloc,
  CFURLRef				  URL,
  CFHTTPMessageRef		  httpResponse,
  CFURLCacheStoragePolicy   recommendedPolicy)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseCreateCopy()
 *  
 */
CFN_EXPORT CFURLResponseRef 
CFURLResponseCreateCopy(
  CFAllocatorRef	 alloc,
  CFURLResponseRef   origResponse)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Simple accessors */
/*
 *  CFURLResponseGetURL()
 *  
 */
CFN_EXPORT CFURLRef 
CFURLResponseGetURL(CFURLResponseRef response)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseGetMIMEType()
 *  
 */
CFN_EXPORT CFStringRef 
CFURLResponseGetMIMEType(CFURLResponseRef response)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseGetExpectedContentLength()
 *  
 */
CFN_EXPORT SInt64 
CFURLResponseGetExpectedContentLength(CFURLResponseRef response) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseGetTextEncodingName()
 *  
 */
CFN_EXPORT CFStringRef 
CFURLResponseGetTextEncodingName(CFURLResponseRef response)   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseGetRecommendedCachePolicy()
 *  
 */
CFN_EXPORT CFURLCacheStoragePolicy 
CFURLResponseGetRecommendedCachePolicy(CFURLResponseRef response) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Returns the absolute time at which the response was created; important for expiry calculations*/
/*
 *  CFURLResponseGetCreationTime()
 *  
 */
CFN_EXPORT CFAbsoluteTime 
CFURLResponseGetCreationTime(CFURLResponseRef response)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
   Returns the expected expiration time.  Entries that should never be cached will return an expiration
   time in the past; entries that never expire will return an expiration time one year from the present
*/
/*
 *  CFURLResponseGetExpirationTime()
 *  
 */
CFN_EXPORT CFAbsoluteTime 
CFURLResponseGetExpirationTime(CFURLResponseRef response)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* The creation time unless something indicates otherwise (like the HTTP headers)*/
/*
 *  CFURLResponseGetLastModifiedDate()
 *  
 */
CFN_EXPORT CFAbsoluteTime 
CFURLResponseGetLastModifiedDate(CFURLResponseRef response)   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  CFURLResponseCopySuggestedFilename()
 *  
 */
CFN_EXPORT CFStringRef 
CFURLResponseCopySuggestedFilename(CFURLResponseRef response) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Caller should not mutate the returned CFHTTPMessageRef*/
/*
 *  CFURLResponseGetHTTPResponse()
 *  
 */
CFN_EXPORT CFHTTPMessageRef 
CFURLResponseGetHTTPResponse(CFURLResponseRef response)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLRESPONSE__ */

