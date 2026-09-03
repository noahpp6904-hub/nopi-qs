#pragma once

#include "../nopi-cmp/nopi-cmp.h"
#include <stddef.h>
#include <stdlib.h>

#define NOPI_LIST_PTR(list) \
    ((uint8_t*)(list))
#define NOPI_LIST_AT(list, index, size) \
    (((uint8_t*)(list)) + (((size_t)(index)) * (size)))

typedef struct nopi_qs nopi_qs_t;

typedef size_t (*nopi_p_fn) \
    (nopi_qs_t*, size_t, size_t);
typedef void (*nopi_qs_part_fn) \
    (nopi_qs_t*);
typedef void (*nopi_qs_fn) \
    (nopi_qs_t*, size_t, size_t);

struct nopi_qs
{
    void* list;
    size_t len;
    size_t size;

    void* p;
    void* temp;

    nopi_cmp_fn cmp_fn;
    nopi_p_fn p_fn;
    nopi_qs_fn qs_fn; 
};

nopi_qs_t*
nopi_qs_init (
    void* list,
    size_t len,
    size_t size,
    nopi_cmp_fn cmp_fn,
    nopi_p_fn p_fn,
    nopi_qs_fn qs_fn
);

void
nopi_qs (
    nopi_qs_t *qs
);

int
nopi_sorted (
    nopi_qs_t* qs
);

size_t
nopi_p_naive (
    nopi_qs_t* qs,    
    size_t start,
    size_t end
);

size_t
nopi_qs_partition_hoare (
    nopi_qs_t* qs,    
    size_t start,
    size_t end
);

void nopi_qs_hoare (
    nopi_qs_t* qs,
    size_t start,
    size_t end
);

void nopi_qs_lomuto (nopi_qs_t* qs);

void nopi_qs_3_way (nopi_qs_t* qs);

void nopi_qs_bentley_mcilroy (nopi_qs_t* qs);