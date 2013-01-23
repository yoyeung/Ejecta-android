/* NOT CoreServices.h
   Copyright (c) 2006-2009 Apple Inc.
   All rights reserved. */

/* BEWARE: This is a bogus header -- it is not in any way equivalent to
   <CoreServices/CoreServices.h> in Mac OS. Its only function is to provide
   a few pieces needed by ColorSync and ImageIO for Windows. */
   
#ifndef COLORSYNC_CORE_SERVICES_H_
#define COLORSYNC_CORE_SERVICES_H_

#include <CoreFoundation/CoreFoundation.h>
#include <AssertMacros.h>

typedef SInt32 Fixed;
typedef unsigned char Str63[64];
typedef char *Ptr;
typedef Ptr *Handle;

#define STACK_UPP_TYPE(name) name

#ifndef nil
# define nil 0
#endif

/* The usual brain-damage. */
enum {
  noErr                         = 0,
  unimpErr                      = -4,
  writErr                       = -20,
  ioErr                         = -36,
  fnOpnErr                      = -38,
  eofErr                        = -39,
  fnfErr                        = -43,
  dupFNErr                      = -48,
  paramErr                      = -50,
  permErr                       = -54,
  memFullErr                    = -108,
  nilHandleErr                  = -109,
  memAdrErr                     = -110,
  memPCErr                      = -114,
  memBCErr                      = -115,
  dirNFErr                      = -120,
  userCanceledErr               = -128,
  cmProfileError                = -170,
  cmMethodError                 = -171,
  cmMethodNotFound              = -175,
  cmProfileNotFound             = -176,
  cmCantConcatenateError	= -178,
  cmUnsupportedDataType         = -181,
  resNotFound                   = -192,
  cmElementTagNotFound          = -4200,
  cmIndexRangeErr               = -4201,
  cmCantDeleteElement           = -4202,
  cmFatalProfileErr             = -4203,
  cmInvalidProfile              = -4204,
  cmInvalidProfileLocation      = -4205,
  cmInvalidColorSpace           = -4209,
  cmInvalidSrcMap               = -4210,
  cmInvalidDstMap               = -4211,
  cmNamedColorNotFound          = -4216,
  cmCantGamutCheckError         = -4217
};

enum {
  gestaltColorSync20 = 0x0200,
  gestaltColorSync25 = 0x0250,
  gestaltColorSync26 = 0x0260
};

enum {
  smSystemScript = -1,
  smRoman = 0
};

enum {
  kUnknownType = 0x3F3F3F3F
};

static __inline UInt16
SwapU16(UInt16 x)
{
  return (x << 8) | (x >> 8);
}

static __inline UInt32
SwapU32(UInt32 x)
{
  return ((x << 24) & 0xFF000000) | ((x << 8) & 0x00FF0000)
    | ((x >> 8) & 0x0000FF00) | ((x >> 24) & 0x000000FF);
}

static __inline uint16_t
OSReadSwapInt16(const volatile void *base, uintptr_t byteOffset)
{
  uint16_t result = *(volatile uint16_t *)((uintptr_t)base + byteOffset);
  return SwapU16(result);
}

static __inline uint32_t
OSReadSwapInt32(const volatile void *base, uintptr_t byteOffset)
{
  uint32_t result = *(volatile uint32_t *)((uintptr_t)base + byteOffset);
  return SwapU32(result);
}

#define Endian16_Swap(value) SwapU16((UInt16)(value))

#define Endian32_Swap(value) SwapU32((UInt32)(value))

#define EndianU32_BtoN(x) SwapU32(x)
#define EndianU16_BtoN(x) SwapU16(x)
#define EndianS32_BtoN(x) ((SInt32)SwapU32(x))
#define EndianS16_BtoN(x) ((SInt16)SwapU16(x))

#define EndianU32_NtoB(x) EndianU32_BtoN(x)
#define EndianU16_NtoB(x) EndianU16_BtoN(x)
#define EndianS32_NtoB(x) EndianS32_BtoN(x)
#define EndianS16_NtoB(x) EndianS16_BtoN(x)

#define EndianU32_LtoN(x) (x)
#define EndianU16_LtoN(x) (x)

#define EndianU32_NtoL(x) (x)
#define EndianU16_NtoL(x) (x)

#define EndianS32_LtoN(x) (x)
#define EndianS16_LtoN(x) (x)
#define EndianS32_NtoL(x) (x)
#define EndianS16_NtoL(x) (x)

#ifdef __cplusplus
extern "C" {
#endif

extern int digittoint(int);
extern size_t strlcat(char *, const char *, size_t);

#ifdef __cplusplus
}
#endif

#endif /* COLORSYNC_CORE_SERVICES_H_ */
