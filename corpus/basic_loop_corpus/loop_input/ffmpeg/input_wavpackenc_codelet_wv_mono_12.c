#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples;
int nb_samples;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024; // 64M int32_t elements = 256MB
    samples = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    if (!samples) {
        exit(1);
    }
    for (int j = 0; j < nb_samples; j++) {
        samples[j] = 0;
    }
    samples[nb_samples - 1] = 1; // ensure loop breaks at last element
}