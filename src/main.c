#include "nopi-cmp/nopi-cmp.h"
#include "nopi-qs/nopi-qs.h"
#include <stdio.h>

#define NUM_THREADS 4
#define LIST_SIZE 100

int
main (
    int argc,
    char* argv[]
)
{
    /* Random list of integers */
    int random_numbers[LIST_SIZE];
    for (int i = 0; i < LIST_SIZE; i++) {
        random_numbers[i] = rand() % 100;
    }

    printf("before sort\n");
    fflush(stdout);

    nopi_qs_t std_hoare = nopi_qs_init (
        random_numbers,
        LIST_SIZE,
        sizeof (random_numbers[0]),
        nopi_cmp_u32,
        nopi_p_naive
    );

    nopi_qs_hoare (&std_hoare);

    printf("after sort\n");
    fflush(stdout);

    for (int i = 0; i < LIST_SIZE; i++)
    {
        printf("%i\n", random_numbers[i]);
    }

    if (nopi_sorted (&std_hoare) > 0)
    {
        printf("sorted\n");
    }
    else
    {
        printf("not sorted\n");
    }

    return 0;
}