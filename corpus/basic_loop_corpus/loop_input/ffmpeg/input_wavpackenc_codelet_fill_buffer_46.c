#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int16_t *sptr;
int nb_samples;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024; // 64M samples to target ~0.01 sec runtime

    sptr = (int16_t*)aligned_alloc(32, nb_samples * sizeof(int16_t));
    dst = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    if (!sptr || !dst) {
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        sptr[j] = (int16_t)(j & 0xFFFF);
    }
}