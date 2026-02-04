#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples_l;
int32_t *samples_r;
int i;
int nb_samples;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024;
    nb_samples = data_size / sizeof(int32_t);

    samples_l = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (int32_t)(j % 1000);
        samples_r[j] = (int32_t)((j + 500) % 1000);
    }
}