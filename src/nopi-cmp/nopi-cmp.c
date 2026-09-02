#include "nopi-cmp.h"

#include <stdint.h>

int
nopi_cmp_u8 (
    const void* a,
    const void* b
)
{
    const uint8_t x = *(const uint8_t*)a;
    const uint8_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int 
nopi_cmp_u16 (
    const void* a,
    const void* b
)
{
    const uint16_t x = *(const uint8_t*)a;
    const uint16_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_u32 (
    const void* a,
    const void* b
)
{
    const uint32_t x = *(const uint8_t*)a;
    const uint32_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_u64 (
    const void* a,
    const void* b
)
{
    const uint64_t x = *(const uint8_t*)a;
    const uint64_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_s8 (
    const void* a,
    const void* b
)
{
    const int8_t x = *(const uint8_t*)a;
    const int8_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_s16 (
    const void* a,
    const void* b
)
{
    const int16_t x = *(const uint8_t*)a;
    const int16_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_s32 (
    const void* a,
    const void* b
)
{
    const int32_t x = *(const uint8_t*)a;
    const int32_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}

int
nopi_cmp_s64 (
    const void* a,
    const void* b
)
{
    const int64_t x = *(const uint8_t*)a;
    const int64_t y = *(const uint8_t*)b;

    return (x > y) - (x < y);
}
