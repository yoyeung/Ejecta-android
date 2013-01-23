/*
	 File:	   CFNetwork/CFURLRequest.h
 
	 Contains:   CFType URL Request header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLREQUEST__
#define __CFURLREQUEST__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypes.h>
#endif

#ifndef __CFHTTPMESSAGE__
#include <CFNetwork/CFHTTPMessage.h>
#endif

#ifndef __CFHTTPCOOKIESPRIV__
#include <CFNetwork/CFHTTPCookiesPriv.h>
#endif

#ifndef __CFURLSTORAGESESSION__
#include <CFNetwork/CFURLStorageSession.h>
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
 *  CFURLRequestCachePolicy
 *  
 *  Discussion:
 *	The caching policy to be used when processing the request
 */
enum CFURLRequestCachePolicy {

  /*
   * Allow the underlying protocol (like HTTP) to choose the most
   */
  kCFURLRequestCachePolicyProtocolDefault = 0,

  /*
   * Ignore any cached contents, requiring that the content come from
   * the origin server
   */
  kCFURLRequestCachePolicyReloadIgnoringCache = 1,

  /*
   * Return the contents of the cache (if any), otherwise load from the
   * origin server
   */
  kCFURLRequestCachePolicyReturnCacheDataElseLoad = 2,

  /*
   * Return the contents of the cache (if any), otherwise, return
   * nothing
   */
  kCFURLRequestCachePolicyReturnCacheDataDontLoad = 3
};
typedef enum CFURLRequestCachePolicy CFURLRequestCachePolicy;


/*
 * CFURLRequestPriority
 * 
 * Discussion: 
 * An optional priority level to be used when considering the order in which
 * requests will be transmitted.  Requests are otherwise transmitted on a 
 * first come, first served basis.
 * All requests of higher priority will be transmitted first.  
 * For example: CFURLRequestPriority = 3 will cause a request to be transmitted before all outstanding requests
 *  of CFURLRequestPriority = 2 or lower.  CFURLRequestPriority = 0 is the lowest priority.
 */
/*enum CFURLRequestPriority {
  kCFURLRequestPriorityLow = 0,
  kCFURLRequestPriorityMedium = 1,
  kCFURLRequestPriorityHigh = 2
};
typedef enum CFURLRequestPriority CFURLRequestPriority;
 */

typedef CFIndex CFURLRequestPriority;

/*!
 @enum CFURLRequestNetworkServiceType
 
 @discussion The CFURLRequestNetworkServiceType enum defines constants that
 can be used to specify the service type to associate with this request.  The
 service type is used to provide the networking layers a hint of the purpose 
 of the request.
 
 @constant kCFURLRequestNetworkServiceTypeDefault Is the default value for an NSURLRequest
 when created.  This value should be left unchanged for the vast majority of requests.
 
 @constant kCFURLRequestNetworkServiceTypeVoIP Specifies that the request is for voice over IP
 control traffic (for the acutal voice data use kCFURLRequestNetworkServiceTypeVoice).
 
 @constant kCFURLRequestNetworkServiceTypeVideo Specifies that the request is for video
 traffic.
 
 @constant kCFURLRequestNetworkServiceTypeBackground Specifies that the request is for background
 traffic (such as a file download).

 @constant kCFURLRequestNetworkServiceTypeBackground Specifies that the request is for background
 traffic (such as a file download).
 */
enum CFURLRequestNetworkServiceType {
	kCFURLRequestNetworkServiceTypeDefault = 0,
	kCFURLRequestNetworkServiceTypeVoIP = 1,
	kCFURLRequestNetworkServiceTypeVideo = 2,
	kCFURLRequestNetworkServiceTypeBackground = 3,
	kCFURLRequestNetworkServiceTypeVoice = 4
};
typedef enum CFURLRequestNetworkServiceType CFURLRequestNetworkServiceType;

/*
 *  CFURLRequestRef
 *  
 *  Discussion:
 *	The type for a request for a URL
 */
// typedef const struct _CFURLRequest*	 CFURLRequestRef;
	
/*
 *  CFURLRequestGetTypeID()
 *  
 *  Discussion:
 *	Returns the type ID for the CFType CFURLRequest
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFTypeID 
CFURLRequestGetTypeID(void)								   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCreate()
 *  
 *  Discussion:
 *	Create a new request
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
 *	  The URL being requested; must not be NULL
 *	
 *	cachePolicy:
 *	  The cache policy to use when retrieving the URL
 *	
 *	timeout:
 *	  How long to attempt to retrieve the URL before timing out
 *	
 *	mainDocumentURL:
 *	  The URL of the document associated with the requested URL
 *  
 *  Result:
 *	The newly created CFURLRequest object
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLRequestCreate(
  CFAllocatorRef			alloc,
  CFURLRef				  URL,
  CFURLRequestCachePolicy   cachePolicy,
  CFTimeInterval			timeout,
  CFURLRef				  mainDocumentURL)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCreateCopy()
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLRequestCreateCopy(
  CFAllocatorRef	alloc,
  CFURLRequestRef   originalRequest)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetURL()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	Returns the URL for the request
 *  
 */
CFN_EXPORT CFURLRef 
CFURLRequestGetURL(CFURLRequestRef request)				   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetCachePolicy()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	Returns the cache policy for the request
 *  
 */
CFN_EXPORT CFURLRequestCachePolicy 
CFURLRequestGetCachePolicy(CFURLRequestRef request)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetTimeoutInterval()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	Returns the timeout interval for the request
 *  
 */
CFN_EXPORT CFTimeInterval 
CFURLRequestGetTimeoutInterval(CFURLRequestRef request)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetMainDocumentURL()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	Returns the URL for the main document associated with the request
 *	(if any)
 *  
 */
CFN_EXPORT CFURLRef 
CFURLRequestGetMainDocumentURL(CFURLRequestRef request)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetProxySettings()
 *  
 *  Discussion:
 *	The setting dictionary matches the SystemConfiguration proxy
 *	dictionary
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLRequestGetProxySettings(CFURLRequestRef request)		 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetSSLProperties()
 *  
 *  Discussion:
 *	See CFNetwork/CFSocketStream.h for a full description of the
 *	expected keys and values in the returned dictionary
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLRequestGetSSLProperties(CFURLRequestRef request)		 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Immutable HTTP extensions; you will need a basic understanding of the structure of HTTP requests to understand these functions */
/*
 *  CFURLRequestCreateHTTPRequest()
 *  
 *  Discussion:
 *	Creates a request for an HTTP URL; use this in preference to
 *	CFURLRequestCreate in order to configure HTTP-specific pieces of
 *	the request like the HTTP headers
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The allocator for allocating the new request
 *	
 *	httpRequest:
 *	  The HTTP request to be issued.  Note that headers in the
 *	  request are not considered complete; when the request is
 *	  issued, the protocol may choose to add additional headers or
 *	  modify the existing headers if neecded to properly process the
 *	  request.  The body of this request will be used unless
 *	  bodyParts, below, is set.
 *	
 *	bodyParts:
 *	  A CFArray containing FileName(CFString) or CFData objects.
 *	The contents of the members of the array will be concatenated and transmitted
 *	as the body of this request.  The bodyParts array takes precedent
 *	over any body set on the httpRequest above.
 *	
 *	cachePolicy:
 *	  The cache policy to use when retrieving the URL
 *	
 *	timeout:
 *	  How long to attempt to retrieve the URL before timing out
 *	
 *	mainDocumentURL:
 *	  The URL of the document associated with the requested URL
 *  
 *  Result:
 *	The newly created CFURLRequest object
 *  
 */
CFN_EXPORT CFURLRequestRef 
CFURLRequestCreateHTTPRequest(
  CFAllocatorRef			alloc,
  CFHTTPMessageRef		  httpRequest,
  CFArrayRef			bodyParts,
  CFURLRequestCachePolicy   cachePolicy,
  CFTimeInterval			timeout,
  CFURLRef				  mainDocumentURL)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyHTTPRequestMethod()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	The HTTP method for this request; this will be "GET" if no method
 *	has been configured on the request
 *  
 */
CFN_EXPORT CFStringRef 
CFURLRequestCopyHTTPRequestMethod(CFURLRequestRef request)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyHTTPRequestBody()
 *  
 */
CFN_EXPORT CFDataRef 
CFURLRequestCopyHTTPRequestBody(CFURLRequestRef request)	  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyHTTPHeaderFieldValue()
 *  
 */
CFN_EXPORT CFStringRef 
CFURLRequestCopyHTTPHeaderFieldValue(
  CFURLRequestRef   request,
  CFStringRef	   headerField)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyAllHTTPHeaderFields()
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFURLRequestCopyAllHTTPHeaderFields(CFURLRequestRef request)  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyHTTPRequest()
 *  
 *  Discussion:
 *	Intended to grab a copy of the final, to-be-transmitted HTTP
 *	request; caller cannot mutate the returned CFHTTPMessageRef and
 *	expect the CFURLRequest to have mutated
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFHTTPMessageRef 
CFURLRequestCopyHTTPRequest(CFURLRequestRef request)		  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * CFURLRequestCopyHTTPRequestBodyParts()
 *  
 * Discussion:
 *  Returns the body parts array for the given request, NULL if body parts have not been set.
 */
CFN_EXPORT CFArrayRef
CFURLRequestCopyHTTPRequestBodyParts(CFURLRequestRef request) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

	
/*
 * CFURLRequestCopyHTTPRequestBodyStream()
 *  
 * Discussion:
 *  Returns a copy of the body stream to be transmitted for a given request.
 *  Reading of the returned stream can in some cases cause loss of data before transmission.
 *  Returns NULL if no body stream.
 */
CFN_EXPORT CFReadStreamRef 
CFURLRequestCopyHTTPRequestBodyStream(CFURLRequestRef request) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyAdditionalHTTPCookies()
 *  
 */
CFN_EXPORT CFArrayRef 
CFURLRequestCopyAdditionalHTTPCookies(CFURLRequestRef request) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCopyHTTPCookieStorage()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFURLRequestCopyHTTPCookieStorage(CFURLRequestRef request)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestGetHTTPCookieStorageAcceptPolicy()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageAcceptPolicy 
CFURLRequestGetHTTPCookieStorageAcceptPolicy(CFURLRequestRef request) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);



/*
 *  CFURLRequestShouldHandleHTTPCookies()
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Result:
 *	Whether this request, when processed, should automatically
 *	consult the shared cookie store and automatically update that
 *	store
 *  
 */
CFN_EXPORT Boolean 
CFURLRequestShouldHandleHTTPCookies(CFURLRequestRef request)  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

CFN_EXPORT void
CFURLRequestSetShouldPipelineHTTP(CFURLRequestRef req, Boolean shouldPipeline, Boolean shouldUsePipeliningHeuristics) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);
	
	
CFN_EXPORT Boolean
CFURLRequestGetShouldPipelineHTTP(CFURLRequestRef req) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);

CFN_EXPORT void
CFURLRequestSetRequestPriority(CFURLRequestRef req, CFURLRequestPriority priority) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);
	
CFN_EXPORT CFURLRequestPriority
CFURLRequestGetRequestPriority(CFURLRequestRef req) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0);

CFN_EXPORT void CFURLRequestSetShouldStartSynchronously(CFURLRequestRef req, Boolean should) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

CFN_EXPORT Boolean CFURLRequestShouldStartSynchronously(CFURLRequestRef req) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
	
CFN_EXPORT CFURLRequestNetworkServiceType
CFURLRequestGetNetworkServiceType(CFURLRequestRef request)	__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_0);
	
/* Mutable requests */

/*
 *  CFMutableURLRequestRef
 *  
 *  Discussion:
 *	The type for a mutable request for a URL
 */
typedef struct _CFURLRequest*		   CFMutableURLRequestRef;
/*
 *  CFURLRequestCreateMutable()
 *  
 *  Summary:
 *	Variant of CFURLRequestCreate that returns a mutable object
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFMutableURLRequestRef 
CFURLRequestCreateMutable(
  CFAllocatorRef			alloc,
  CFURLRef				  URL,
  CFURLRequestCachePolicy   cachePolicy,
  CFTimeInterval			timeout,
  CFURLRef				  mainDocumentURL)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestCreateMutableCopy()
 *  
 *  Summary:
 *	Creates a mutable copy of an existing request
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT CFMutableURLRequestRef 
CFURLRequestCreateMutableCopy(
  CFAllocatorRef	alloc,
  CFURLRequestRef   origRequest)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Simple accessors to configure a mutable request*/
/*
 *  CFURLRequestSetURL()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetURL(
  CFMutableURLRequestRef   mutableRequest,
  CFURLRef				 url)							   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetCachePolicy()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetCachePolicy(
  CFMutableURLRequestRef	mutableRequest,
  CFURLRequestCachePolicy   cachePolicy)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Currently no-ops*/
/*
 *  CFURLRequestSetShouldCacheResponse()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetShouldCacheResponse(
  CFMutableURLRequestRef   mutableRequest,
  Boolean				  shouldCacheResponse)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetTimeoutInterval()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetTimeoutInterval(
  CFMutableURLRequestRef   mutableRequest,
  CFTimeInterval		   timeoutInterval)				   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetMainDocumentURL()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetMainDocumentURL(
  CFMutableURLRequestRef   mutableRequest,
  CFURLRef				 mainDocumentURL)				   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Currently no-ops*/
/*
 *  CFURLRequestSetMaximumPermissibleContentLength()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetMaximumPermissibleContentLength(
  CFMutableURLRequestRef   mutableRequest,
  SInt64				   maximumLength)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetProxySettings()
 *  
 *  Discussion:
 *	Configures any custom proxy settings
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	mutableRequest:
 *	  The request to be changed
 *	
 *	proxySettings:
 *	  A dictionary setting the desired SSL properties; the format
 *	  should match the dictionary used by SystemConfiguration. A NULL
 *	  dictionary means use the default proxy settings for the system;
 *	  non-NULL but empty means no proxies at all.
 *  
 */
CFN_EXPORT void 
CFURLRequestSetProxySettings(
  CFMutableURLRequestRef   mutableRequest,
  CFDictionaryRef		  proxySettings)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetSSLProperties()
 *  
 *  Discussion:
 *	Configures how any SSL communication with the server will be
 *	performed, including how the server's certificate is verified.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	mutableRequest:
 *	  The request to be changed
 *	
 *	sslProperties:
 *	  A dictionary setting the desired SSL properties; the format
 *	  should match the dictionary used by CFSocketStream. See
 *	  CFNetwork/CFSocketStream.h for a full description of the
 *	  appropriate keys and values
 *  
 */
CFN_EXPORT void 
CFURLRequestSetSSLProperties(
  CFMutableURLRequestRef   mutableRequest,
  CFDictionaryRef		  sslProperties)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Mutable HTTP requests */
/*
 *  CFURLRequestCreateMutableHTTPRequest()
 *  
 *  Summary:
 *	Variant of CFURLRequestCreateHTTPRequest that returns a mutable
 *	object.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
 
CFN_EXPORT CFMutableURLRequestRef 
CFURLRequestCreateMutableHTTPRequest(
  CFAllocatorRef			alloc,
  CFHTTPMessageRef		  httpRequest,
  CFArrayRef			bodyParts,
  CFURLRequestCachePolicy   cachePolicy,
  CFTimeInterval			timeout,
  CFURLRef				  mainDocumentURL)				  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Simple accessors for setting the HTTP properties of a request */
/*
 *  CFURLRequestSetHTTPRequestMethod()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPRequestMethod(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFStringRef			  httpMethod)						__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetHTTPHeaderFieldValue()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPHeaderFieldValue(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFStringRef			  httpHeaderField,
  CFStringRef			  httpHeaderFieldValue)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetMultipleHTTPHeaderFields()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetMultipleHTTPHeaderFields(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFDictionaryRef		  headerFields)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestAppendHTTPHeaderFieldValue()
 *  
 *  Discussion:
 *	Extends the value of an HTTP header field.  This is useful if you
 *	want to simply add an additional (comma-separated) value to an
 *	HTTP header.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestAppendHTTPHeaderFieldValue(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFStringRef			  httpHeaderField,
  CFStringRef			  additionalHttpHeaderFieldValue)	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Note that setting the body data is mutually exclusive with setting the body stream; setting either one will clear the other */
/*
 *  CFURLRequestSetHTTPRequestBody()
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPRequestBody(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFDataRef				httpBody)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetHTTPRequestBodyParts()
 *  
 *  Discussion:
 *	Sets an array of CFTypeRefs from which the body of the HTTP should come.
 *	Currently only FileName(CFStringRef) and CFData objects are supported.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPRequestBodyParts(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFArrayRef		   bodyParts)						__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetHTTPRequestBodyStream()
 *  
 *  Discussion:
 *	This function is deprecated.  Given a fresh, unscheduled body-stream,
 *	 SetHTTPRequestBodyStream will cause the contents of the stream to be
 *	 transmitted to the remote host.  This can and will cause the transmission
 *	 to hang in the event that the stream needs to be retried, this method MUST
 *	 only be used by Foundation, and Foundation SHOULD move to the body parts API
 *	 as well.
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void CFURLRequestSetHTTPRequestBodyStream(
  CFMutableURLRequestRef req, 
  CFReadStreamRef bodyStream)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  CFURLRequestSetShouldHandleHTTPCookies()
 *  
 *  Discussion:
 *	Sets whether the request should retrieve cookies from the shared
 *	cookie store before transmission and update the shared cookie
 *	store from the server's response
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestSetShouldHandleHTTPCookies(
  CFMutableURLRequestRef   mutableHTTPRequest,
  Boolean				  shouldHandleCookies)			   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetAdditionalHTTPCookies()
 *  
 *  Discussion:
 *	Sets additional cookies (to be used in addition to any cookies in
 *	the shared cookie store) on the request
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestSetAdditionalHTTPCookies(
  CFMutableURLRequestRef   mutableHTTPRequest,
  CFArrayRef			   additionalCookies)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetHTTPCookieStorage()
 *  
 *  Discussion:
 *	Sets cookie storage (to be used instead of default storage) on
 *	the request
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPCookieStorage(
  CFMutableURLRequestRef   req,
  CFHTTPCookieStorageRef   cookieStorage)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLRequestSetHTTPCookieStorageAcceptPolicy()
 *  
 *  Discussion:
 *	Sets cookie acceptance policy on the request
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 */
CFN_EXPORT void 
CFURLRequestSetHTTPCookieStorageAcceptPolicy(
  CFMutableURLRequestRef			req,
  CFHTTPCookieStorageAcceptPolicy   cookieStorageAcceptPolicy) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFReadStreamCreateWithFormArray()
 *  
 *  Discussion:
 *	Constructs and returns a read stream for the given form data
 *  
 *  Mac OS X threading:
 *	Thread safe
 *  
 *  Parameters:
 *	
 *	alloc:
 *	  The allocator to use when creating the stream
 *	
 *	formArray:
 *	  A CFArray whose elements are all either CFDatas or CFStrings.
 *	  The CFStrings are interpreted as paths for files to be loaded;
 *	  the CFDatas are interpreted as raw bytes. Note that if the
 *	  array contains elements that are neither CFDatas nor CFStrings,
 *	  or if the CFStrings are not valid paths (or do not point to
 *	  valid files), this function will still return a valid read
 *	  stream.  However, at some point, reading from that stream will
 *	  produce an error.
 *  
 *  Result:
 *	A read stream which, when read, returns the contents of formArray
 *	in order.  For CFDatas, it returns the bytes of the data; for
 *	strings, it returns the bytes of the file at the path for the
 *	string.
 *  
 */
CFN_EXPORT CFReadStreamRef 
CFReadStreamCreateWithFormArray(
  CFAllocatorRef   alloc,
  CFArrayRef	   formArray)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	
	
CFN_EXPORT void
CFURLRequestSetNetworkServiceType(CFMutableURLRequestRef request, CFURLRequestNetworkServiceType networkServiceType)	__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_0);

/*
 * CFURLRequestIsIdempotent
 *  Returns true if the request can be safely retried without changing the server state.  HTTP HEAD and GET are idempotent methods.
 *
 */
CFN_EXPORT Boolean
CFURLRequestIsIdempotent(CFURLRequestRef req) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
	

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLREQUEST__ */

