/*
 *  WKCACFImage.h
 *  WebKitQuartzCoreAdditions
 *
 *  Created by Adam Roben on 3/25/11.
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef WKCACFImage_h
#define WKCACFImage_h

#include <WebKitQuartzCoreAdditions/WebKitQuartzCoreAdditionsBase.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Returns the type identifier of all WKCACFImage instances. */
WKQCA_EXPORT CFTypeID WKCACFImageGetTypeID(void);

/* Return the dimensions of the image. */
WKQCA_EXPORT size_t WKCACFImageGetWidth(WKCACFImageRef image);
WKQCA_EXPORT size_t WKCACFImageGetHeight(WKCACFImageRef image);

/* Returns a file mapping object which contains the bits of the image. (Note that this does not
 * copy the bits; the returned file mapping object points to the same underlying bits that the
 * image itself uses.) The bits are in the format of a top-down, 32-bit DIB. It is the caller's
 * responsibility to destroy the file mapping via ::CloseHandle. */
WKQCA_EXPORT HANDLE WKCACFImageCopyFileMapping(WKCACFImageRef image, size_t* fileMappingSize);

#ifdef __cplusplus
}
#endif

#endif // WKCACFImage_h
