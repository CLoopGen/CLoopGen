#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *samples_l;
int32_t *samples_r;
int i;
int nb_samples;
int32_t lor;
int32_t diff;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data per array
    nb_samples = data_size / sizeof(int32_t);

    samples_l = (int32_t*)aligned_alloc(32, data_size);
    samples_r = (int32_t*)aligned_alloc(32, data_size);

    if (!samples_l || !samples_r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j % 2 == 0) ? ((j + 1) * 3) : 0;
        samples_r[j] = (j % 2 == 1) ? ((j + 1) * 5) : 0;
    }

    lor = 0;
    diff = 0;
    i = 0;
}