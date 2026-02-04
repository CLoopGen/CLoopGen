#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int nb_samples;
int i;
int32_t *sptr;

void init_vars() {
    nb_samples = 32 * 1024 * 1024 / sizeof(int32_t); // ~128MB total data (64MB per array)
    sptr = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));
    dst = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    for (int j = 0; j < nb_samples; j++) {
        sptr[j] = (int32_t)(j % 65536);
    }

    i = 0;
}