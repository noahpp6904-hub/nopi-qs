#pragma once

typedef int (*nopi_cmp_fn)(const void*, const void*);

/** Compare two unsigned 8-Bit integers */
int
nopi_cmp_u8 (
    const void* a,
    const void* b
);
/** Compare two unsigned 16-Bit integers */
int
nopi_cmp_u16 (
    const void* a,
    const void* b
);
/** Compare two unsigned 32-Bit integers */
int
nopi_cmp_u32 (
    const void* a,
    const void* b
);
/** Compare two unsigned 64-Bit integers */
int 
nopi_cmp_u64 (
    const void* a,
    const void* b
);

/** Compare two signed 8-Bit integers */
int
nopi_cmp_s8 (
    const void* a,
    const void* b);
/** Compare two signed 16-Bit integers */
int
nopi_cmp_s16 (
    const void* a, 
    const void* b
);
/** Compare two signed 32-Bit integers */
int
nopi_cmp_s32 (
    const void* a,
    const void* b
);
/** Compare two signed 64-Bit integers */
int
nopi_cmp_s64 (
    const void* a,
    const void* b
);
