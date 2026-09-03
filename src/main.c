#include "nopi-cmp/nopi-cmp.h"
#include "nopi-qs/nopi-qs.h"
#include "nopi-timer/nopi-timer.h"
#include <stdio.h>

#define NUM_THREADS 4

void test_qs (
    nopi_qs_t* ctx[],
    size_t len
);

int
main (
    int argc,
    char* argv[]
)
{
    /* Standart qs with hoare */
    nopi_qs_t* qs_hoare_ctx = nopi_qs_init (
        NULL,
        1,
        1,
        nopi_cmp_u32,
        nopi_p_naive,
        nopi_qs_hoare
    );

    nopi_qs_t* ctx[] = {
        qs_hoare_ctx
    };

    test_qs (ctx, 1);

    return 0;
}

void test_qs (
    nopi_qs_t* ctx[],
    size_t len
)
{
    /* Iterate trough all quickssort contexts */
    for (size_t i = 0; i < len; i++)
    {
        nopi_qs_t* curr_ctx = ctx[i];

        /* Select the sample size */
        for (size_t sample_size = 1000; sample_size < 100'000'000; sample_size *= 10)
        {
            int *numbers = malloc (sample_size * sizeof(int));
            if (numbers == NULL)
                exit (EXIT_FAILURE);

            curr_ctx->len = sample_size;
            curr_ctx->size = (sizeof(int));
            curr_ctx->temp = malloc (sizeof (int));
            curr_ctx->p = malloc (sizeof (int));

            double time[100];
            double avg_time = 0.0;

            /* Test the implementation 100 times with the sample size */
            for (int test_cycle = 0; test_cycle < 100; test_cycle++)
            {
                for (size_t r = 0; r < sample_size; r++)
                {
                    numbers[r] = rand();
                }
                curr_ctx->list = numbers;

                double curr_time = nopi_timer_qs (curr_ctx);

                time[test_cycle] = curr_time;
                avg_time += curr_time;
            }
            avg_time /= 100;
            printf ("Average time: %f, with %zu numbers\n", avg_time, sample_size);
            
            free (numbers);
            free (curr_ctx->temp);
            free (curr_ctx->p);
        }
    }
}
