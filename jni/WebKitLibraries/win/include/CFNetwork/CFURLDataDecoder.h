/*
	 File:	   CFNetwork/CFURLDataDecoder.h
 
	 Contains:   CoreFoundation Network Data Decoder Header
 
	 Copyright:  Copyright (c) 2007-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/

#ifndef __CFURLDATADECODER__
#define __CFURLDATADECODER__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __CFURLRESPONSE__
#include <CFNetwork/CFURLResponse.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  CFURLDataDecoder
 */
typedef struct _CFURLDataDecoder*		  CFURLDataDecoderRef;

CFN_EXPORT
CFTypeID CFURLDataDecoderGetTypeID(void);

CFN_EXPORT
CFURLDataDecoderRef CFURLDataDecoderCreateWithResponse(CFAllocatorRef alloc, CFURLResponseRef response);

// CFURLDownloadDecoderDecodeData will return NULL and set needsMoreData if the decoder could possibly decode
// the data if more of it were available (the case we ran into was sending less than 10 bytes of data to the 
// gzip decoder which needs at least 10 bytes to intepret the header).
CFN_EXPORT
CFDataRef CFURLDataDecoderDecodeData(CFURLDataDecoderRef dataDecoder, CFDataRef data, Boolean *needsMoreData);

CFN_EXPORT
CFDataRef CFURLDataDecoderDecodeDataArray(CFURLDataDecoderRef dataDecoder, CFArrayRef dataArray, Boolean *needsMoreData);

CFN_EXPORT
Boolean CFURLDataDecoderIsFinishedDecoding(CFURLDataDecoderRef dataDecoder);

#ifdef __cplusplus
}
#endif

#endif // __CFURLDATADECODER__
