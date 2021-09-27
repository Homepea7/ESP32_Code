#ifndef __COMMON_H__
#define __COMMON_H__

#include "stdint.h"

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define S8_MIN -128
#define S8_MAX 127
#define U8_MAX 255

#define S16_MIN -32768
#define S16_MAX 32767
#define U16_MAX 65535

#define S32_MIN (-2147483647 - 1)
#define S32_MAX 2147483647
#define U32_MAX 4294967295U

#define S64_MIN (-9223372036854775807LL - 1LL)
#define S64_MAX 9223372036854775807LL
#define U64_MAX 18446744073709551615ULL

u8 AbsS8(s8 x)
{
    return x >= 0 ? x : -x;
}

u16 AbsS16(s16 x)
{
    return x >= 0 ? x : -x;
}

u32 AbsS32(s32 x)
{
    return x >= 0 ? x : -x;
}

u64 AbsS64(s64 x)
{
    return x >= 0 ? x : -x;
}

u16 AbsDiffU8(u8 x, u8 y)
{
    return AbsS16((s16)x - (s16)y);
}
u16 AbsDiffS8(s8 x, s8 y)
{
    return AbsS16((s16)x - (s16)y);
}

u32 AbsDiffU16(u16 x, u16 y)
{
    return AbsS32((s32)x - (s32)y);
}

u32 AbsDiffS16(s16 x, s16 y)
{
    return AbsS32((s32)x - (s32)y);
}

u64 AbsDiffU32(u32 x, u32 y)
{
    return AbsS64((s64)x - (s64)y);
}

u64 AbsDiffS32(s32 x, s32 y)
{
    return AbsS64((s64)x - (s64)y);
}

#endif
