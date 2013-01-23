/*
	 File:	   CFNetwork/CFHTTPCookies.h
 
	 Contains:   CFType HTTPCookies header
 
	 Copyright:  Copyright (c) 2006-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFHTTPCOOKIES__
#define __CFHTTPCOOKIES__


#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#include <Availability.h>

/*
 * For building on SnowLeopard...
 * This should be removed once Availability.h revs for SL
 */
#if TARGET_OS_WIN32
#define _CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE	/* WHATEVER */
#elif __MAC_10_7
#define _CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE	__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_3_0)
#else
#define _CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE	__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0)
#endif


#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 2)

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif

typedef struct OpaqueCFHTTPCookieStorage*  CFHTTPCookieStorageRef;
typedef const struct OpaqueCFHTTPCookie*	  CFHTTPCookieRef;

/*
 * These strings match what is in NSHTTPCookie.h
 * and represent the key values for a cookie property dictionary
 * and for searching purposes.
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieName;			/* CFStringRef */
CFN_EXPORT const CFStringRef kCFHTTPCookieVersion;		/* CFNumberRef, default of nil == version 1 */
CFN_EXPORT const CFStringRef kCFHTTPCookieValue;		/* CFStringRef */
CFN_EXPORT const CFStringRef kCFHTTPCookieDomain;		/* CFStringRef, puny-encoded */
CFN_EXPORT const CFStringRef kCFHTTPCookiePath;			/* CFStringRef */
CFN_EXPORT const CFStringRef kCFHTTPCookieSecure;		/* CFBooleanRef or CFStringRef=="true" */
CFN_EXPORT const CFStringRef kCFHTTPCookieExpires;		/* CFDateRef */
CFN_EXPORT const CFStringRef kCFHTTPCookieComment;		/* CFStringRef */
CFN_EXPORT const CFStringRef kCFHTTPCookieCommentURL;	/* CFStringRef on output, CFStringRef or CFURLRef on input */
CFN_EXPORT const CFStringRef kCFHTTPCookieDiscard;		/* CFBooleanRef or CFStringRef=="true" */
CFN_EXPORT const CFStringRef kCFHTTPCookieMaximumAge;		/* CFNumberRef */
CFN_EXPORT const CFStringRef kCFHTTPCookiePort;			/* CFNumberRef or CFArray of CFNumberRef */

CFN_EXPORT const CFStringRef kCFHTTPCookieOriginURL;	/* CFStringRef on output, CFStringRef or CFURLRef on input.  One of kCFHTTPCookieOriginalURL or kCFHTTPCookieDomain must be specified. */
	
enum {
  kCFHTTPCookieStorageAcceptPolicyAlways = 0,
  kCFHTTPCookieStorageAcceptPolicyNever = 1,
  kCFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain = 2
};

enum {
  CFHTTPCookieStorageAcceptPolicyAlways = kCFHTTPCookieStorageAcceptPolicyAlways,
  CFHTTPCookieStorageAcceptPolicyNever = kCFHTTPCookieStorageAcceptPolicyNever,
  CFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain = kCFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain
};

typedef int							 CFHTTPCookieStorageAcceptPolicy;
enum CFHTTPCookieFlags {
  CFHTTPCookieSecureFlag		= 1 << 0,
  CFHTTPCookieSessionOnlyFlag   = 1 << 1,
  CFHTTPCookieHTTPOnlyFlag      = 1 << 2
};
typedef enum CFHTTPCookieFlags CFHTTPCookieFlags;

	
/*
 *  kCFHTTPCookieLocalFileDomain
 *   a special hostname to be used for cookies set by local file (file://) URLs
 */
CFN_EXPORT CFStringRef const kCFHTTPCookieLocalFileDomain		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);

/*
 *  CFHTTPCookieGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFHTTPCookieGetTypeID(void)								   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCreateWithProperties()
 *  
 */
CFN_EXPORT CFHTTPCookieRef 
CFHTTPCookieCreateWithProperties(
  CFAllocatorRef	inAllocator,
  CFDictionaryRef   inProperties)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCreateWithResponseHeaderFields()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieCreateWithResponseHeaderFields(
  CFAllocatorRef	inAllocator,
  CFDictionaryRef   headerFields,
  CFURLRef		  inURL)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCopyRequestHeaderFields()
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFHTTPCookieCopyRequestHeaderFields(
  CFAllocatorRef   inAllocator,
  CFArrayRef	   inCookies)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieCopyProperties()
 *  
 */
CFN_EXPORT CFDictionaryRef 
CFHTTPCookieCopyProperties(CFHTTPCookieRef inCookie)		  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieGetVersion()
 *  
 */
CFN_EXPORT CFIndex 
CFHTTPCookieGetVersion(CFHTTPCookieRef inCookie)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 * CFHTTPCookie object accessors.  At the foundation layer, these are all 
 * autoreleased values, so were made Get calls in the C port for consistency.  
 * However, since we now need to change the internal format of the cookie object, 
 * we no longer are holding CFType values ready to be handed out, pinned by the cookie 
 * object itself.  Because of this, the CFHTTPCookieGet* calls are all deprecated in 
 * favor of CFHTTPCookieCopy* calls.  The exception to this is in the calls that used 
 * to return CFDateRef objects - these will now return a CFAbsoluteTime scalar instead.
 */
	
	
/*
 *  CFHTTPCookieGetFlags()
 *  
 */
CFN_EXPORT unsigned int 
CFHTTPCookieGetFlags(CFHTTPCookieRef inCookie)					__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	

CFN_EXPORT CFStringRef 
CFHTTPCookieCopyName(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;

CFN_EXPORT CFStringRef 
CFHTTPCookieCopyValue(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
	
CFN_EXPORT CFAbsoluteTime 
CFHTTPCookieGetExpirationTime(CFHTTPCookieRef inCookie)			_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
	
CFN_EXPORT CFAbsoluteTime 
CFHTTPCookieGetCreationTime(CFHTTPCookieRef inCookie)		   _CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
	
CFN_EXPORT CFStringRef 
CFHTTPCookieCopyDomain(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;


CFN_EXPORT CFStringRef 
CFHTTPCookieCopyPath(CFHTTPCookieRef inCookie)					_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
	
CFN_EXPORT CFStringRef 
CFHTTPCookieCopyComment(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
CFN_EXPORT CFURLRef 
CFHTTPCookieCopyCommentURL(CFHTTPCookieRef inCookie)			_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;
	
	
CFN_EXPORT CFArrayRef
CFHTTPCookieCopyPortArray(CFHTTPCookieRef inCookie)				_CFNETWORK_COOKIES_PREFERRED_SPI_ON_DESKTOP_AND_PHONE;

	
/*
 * Cookie Storage
 */

typedef CALLBACK_API_C( void , CFHTTPCookieStorageChangedProcPtr )(CFHTTPCookieStorageRef inStorage, void *context);
/*
 *  CFHTTPCookieStorageAddObserver()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageAddObserver(
  CFHTTPCookieStorageRef			  inStorage,
  CFRunLoopRef						inRunloop,
  CFStringRef						 inRunloopMode,
  CFHTTPCookieStorageChangedProcPtr   callback,
  void *							  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageRemoveObserver()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageRemoveObserver(
  CFHTTPCookieStorageRef			  inStorage,
  CFRunLoopRef						inRunloop,
  CFStringRef						 inRunloopMode,
  CFHTTPCookieStorageChangedProcPtr   callback,
  void *							  context)				__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetTypeID()
 *  
 */
CFN_EXPORT CFTypeID 
CFHTTPCookieStorageGetTypeID(void)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * _CFHTTPCookieStorageCreateWithProperties
 *
 * If NULL is passed, then a PRIVATE, NON-PERSISENT store is created.  This store will be
 * process private entirely.
 *
 * Typically, cookie storages are going to be created by file, in memory, or by identifier
 * which is some combination of these flags.
 * 
 * Future flags may configure attributes of the cookie storage at creation time (number
 * of cookies, maximum cookie size, etc.)
 */

/*
 * Storage disposition.  If neither of these keys are present, the store will be in-this-process private memory only.
 * File based storage are treated as having a journal which must be replayed if multiple processes
 * are updating the storage at the same time.  Identifier based storages may revert to file based storage (with
 * an implementation specific location) if there is no sharing mechanism (eg, cookied.)
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageFileLocation;			/* a CFURLRef - only for creating private stores on disk */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageSessionIdentifier;		/* a CFStringRef */

/*
 * Persistence for identifier based sessions.  If not present, the session is considered to be persistent.
 * Otherwise, if kCFBooleanFalse, when all clients of the storage session are released
 * the storage will be forever more unavailable
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieStoragePersistent;			/* a CFBooleanRef */

/*
 * Options for file based storages.  Identifier based storages are always binary when persisted.
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageFileType;				/* kCFHTTPCookieStorageFileTypeBinary, kCFHTTPCookieStorageFileTypeXML.  Default is Binary */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageFileTypeBinary;		/* value */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageFileTypeXML;			/* value */

/*
 * Storage objects may have base storage objects.  This will typically
 * only be used for in process private storages.
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageBaseStorage;			/* CFHTTPCookieStorageRef */

/*
 * Configure the cookie acceptance policy up front
 */
CFN_EXPORT const CFStringRef kCFHTTPCookieStorageAcceptancePolicy;		/* a CFNumber containting an scalar value of CFHTTPCookieStorageAcceptPolicy */

CFN_EXPORT CFHTTPCookieStorageRef
_CFHTTPCookieStorageCreateWithProperties(CFAllocatorRef alloc, CFDictionaryRef properties)			 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

	
	
	
/*
 *  CFHTTPCookieStorageCreateInMemory()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateInMemory(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   baseStorage)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateFromFile()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateFromFile(
  CFAllocatorRef		   inAllocator,
  CFURLRef				 inStorageLocation,
  CFHTTPCookieStorageRef   baseStorage)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateArchive()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCreateArchive(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   inStorage)						 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCreateFromArchive()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageCreateFromArchive(
  CFAllocatorRef   inAllocator,
  CFArrayRef	   inArchive)								 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageScheduleWithRunLoop()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageScheduleWithRunLoop(
  CFHTTPCookieStorageRef   inStorage,
  CFRunLoopRef			 inRunloop,
  CFStringRef			  inRunloopMode)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageUnscheduleFromRunLoop()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageUnscheduleFromRunLoop(
  CFHTTPCookieStorageRef   inStorage,
  CFRunLoopRef			 inRunloop,
  CFStringRef			  inRunloopMode)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetBaseStorage()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageRef 
CFHTTPCookieStorageGetBaseStorage(CFHTTPCookieStorageRef inStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageGetCookieAcceptPolicy()
 *  
 */
CFN_EXPORT CFHTTPCookieStorageAcceptPolicy 
CFHTTPCookieStorageGetCookieAcceptPolicy(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookieAcceptPolicy()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookieAcceptPolicy(
  CFHTTPCookieStorageRef			inCookieStorage,
  CFHTTPCookieStorageAcceptPolicy   inCookieAcceptPolicy)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCopyCookiesForURL()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCopyCookiesForURL(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFURLRef				 inURL,
  Boolean				  sendSecureCookies)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookie()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookie(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFHTTPCookieRef		  inCookie)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSetCookies()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageSetCookies(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFArrayRef			   inCookies,
  CFURLRef				 inURL,
  CFURLRef				 inMainDocumentURL)				 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageCopyCookies()
 *  
 */
CFN_EXPORT CFArrayRef 
CFHTTPCookieStorageCopyCookies(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 * Returns an array of CFHTTPCookies which has been sorted by key based on the fields in fieldOrder.
 * Domain strings are sorted according to their actual encoding (as opposed to storage encoding)
 * The field order array will either be the name of the field, or an array containing two elements, the
 * name of the field and a CFBooleanRef.  kCFBooleanTrue indicates ascending sort (the default) and kCFBooleanFalse indicates descending.
 */
CFN_EXPORT CFArrayRef CFHTTPCookieStorageCopyCookiesSortedByFields(CFHTTPCookieStorageRef inCookieStorage, CFArrayRef fieldOrder) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

/*
 * The main cookie searching and sorting routine.
 * To return all cookies, searchDict == NULL, searchOptions == kCFHTTPCookieSearchInvert
 * To emulate CFHTTPCookieStorageCopyCookiesForURL, searchDict = { Domain: host, Secure: kCFBooleanTrue, Port: }, searchOptions = { kCFHTTPCookieSearchDomainNameRules, kCFHTTPCookieSearchStringsExactly }, NULL
 * Sort order is as per CFHTTPCookieStorageCopyCookiesSortedByFields.
 */
	
enum CFHTTPCookieStorageSearchOptions {
	kCFHTTPCookieSearchOptionsNone = 0,				// The default is case insensitive, partial string sorting, any matching
	kCFHTTPCookieSearchCaseSensitive = (1 << 0),	// Require case sensitivity
	kCFHTTPCookieSearchStringsExactly = (1 << 1),	// Whole word matching
	kCFHTTPCookieSearchDomainNameRules = ( 1 << 2),	// Used to indicate that we want to do the domain name expansion stuff for this search (experimental!)
	kCFHTTPCookieSearchPortMatchesAll = (1 << 3),	// If this bit is set, then ports specified in the search must be present in the cookie
	kCFHTTPCookieSearchRequireExactMatch = (1 << 4),// All the terms must compare favorably
	kCFHTTPCookieSearchInvert = (1 << 5),			// Return items that *do not* meet the criteria
};

CFN_EXPORT CFArrayRef CFHTTPCookieStorageCopyCookiesMatching(CFHTTPCookieStorageRef inCookieStorage, CFDictionaryRef searchDict, CFOptionFlags searchOptions, CFArrayRef sortOrder)  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	
/*
 *  CFHTTPCookieStorageDeleteCookie()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageDeleteCookie(
  CFHTTPCookieStorageRef   inCookieStorage,
  CFHTTPCookieRef		  inCookie)						  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageDeleteAllCookies()
 *  
 */
CFN_EXPORT void 
CFHTTPCookieStorageDeleteAllCookies(CFHTTPCookieStorageRef inCookieStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFHTTPCookieStorageSyncStorageNow()
 *  
 */
CFN_EXPORT void
CFHTTPCookieStorageSyncStorageNow(CFHTTPCookieStorageRef inStorage) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageSetCookiesWithResponseHeaderFields()
 *  
 */
CFN_EXPORT void 
_CFHTTPCookieStorageSetCookiesWithResponseHeaderFields(
  CFHTTPCookieStorageRef			inCookieStorage,
  CFURLRef						  inURL,
  CFDictionaryRef				   headerFields,
  CFURLRef						  inPolicyURL,
  CFHTTPCookieStorageAcceptPolicy   inCookieAcceptPolicy)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFHTTPCookieStorageCopyRequestHeaderFieldsForURL()
 *  
 */
CFN_EXPORT CFDictionaryRef 
_CFHTTPCookieStorageCopyRequestHeaderFieldsForURL(
  CFAllocatorRef		   inAllocator,
  CFHTTPCookieStorageRef   inCookieStorage,
  CFURLRef				 inRequestURL)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 * CFHTTPCookieIsSecure()
 *
 * cookies marked as secure should only be sent via secure connections
 * and should not go to JavaScript applications.
 */
CFN_EXPORT Boolean
CFHTTPCookieIsSecure(
  CFHTTPCookieRef cookie)					 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);
	
/* CFHTTPCookieIsHTTPOnly()
 *
 * cookies marked as httponly should only be sent via http or secure connections
 * and should not go to JavaScript applications.
 */
CFN_EXPORT Boolean
CFHTTPCookieIsHTTPOnly(
  CFHTTPCookieRef cookie)					__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

	
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __CFHTTPCOOKIESPRIV__ */

