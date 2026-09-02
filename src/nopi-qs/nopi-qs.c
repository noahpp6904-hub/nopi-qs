#include "nopi-qs.h"
#include <stdint.h>
#include <memory.h>

#define AT(list, index, size) \
    NOPI_LIST_AT (list, index, size)

nopi_qs_t
nopi_qs_init (
    void* list,
    size_t len,
    size_t size,
    nopi_cmp_fn cmp_fn,
    nopi_p_fn p_fn
)
{
    nopi_qs_t q;
    q.list = list;
    q.len = len;
    q.size = size;
    q.p = malloc(size);
    q.temp = malloc(size);
    q.cmp_fn = cmp_fn;
    q.p_fn = p_fn;

    return q;
}

static void
nopi_swap (
    nopi_qs_t *qs,
    void* a,
    void* b
)
{
    memcpy (
        qs->temp,
        b,
        qs->size
    );
    memcpy (
        b,
        a,
        qs->size
    );
    memcpy (
        a,
        qs->temp,
        qs->size
    );
}

int
nopi_sorted (
    nopi_qs_t* qs
)
{
    if (qs->list == NULL || qs->cmp_fn == NULL) return 0;

    for (size_t i = 0; i + 1 < qs->len; i++)
    {
        if (qs->cmp_fn (
            AT (qs->list, i, qs->size),
            AT (qs->list, (i + 1), qs->size)) > 0)
        {
            return 0;
        }
    }
    return 1;
}




size_t
nopi_p_naive (
    nopi_qs_t* qs,    
    size_t start,
    size_t end
)
{
    return (start + ((end - start) / 2));
}

size_t
nopi_qs_partition_hoare (
    nopi_qs_t* qs,    
    size_t start,
    size_t end
)
{
    /* Select the index of the pivot */
    size_t pivot_index = qs->p_fn (
        qs,
        start,
        end
    );

    /* Copy pivot to make it compareable */
    memcpy (
        qs->p,
        AT (qs->list, pivot_index, qs->size),
        qs->size   
    );

    /* Compare against the pivot */
    size_t l = start;
    size_t r = end;

    while (1) 
    {
        while (qs->cmp_fn ( AT (qs->list, l, qs->size), qs->p) < 0) l++;

        while (qs->cmp_fn ( AT (qs->list, r, qs->size), qs->p) > 0) r--;

        if (l >= r) break;

        nopi_swap (
            qs,
            AT (qs->list, l, qs->size),
            AT (qs->list, r, qs->size)
        );
        l++;
        r--;
    }

    return r;
}

void
nopi_qs_sort_hoare (
   nopi_qs_t *qs,
   size_t start,
   size_t end
)
{
    if (start >= end)
        return;

    size_t split = nopi_qs_partition_hoare (
        qs,
        start,
        end
    );

     /* left partition */
    nopi_qs_sort_hoare (
        qs,
        start,
        split
    );
    /* right partition */
    nopi_qs_sort_hoare (
        qs,
        split + 1,
        end
    );
}

void
nopi_qs_hoare (
    nopi_qs_t *qs
)
{
    if (qs->len <= 1) return;
    if (qs->size == 0) return;
    if (qs->list == NULL || qs->cmp_fn == NULL || qs->p_fn == NULL) return;

    nopi_qs_sort_hoare (
        qs,
        0,
        qs->len - 1
    );
}