#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples;
int nb_samples;
int shift;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024 / sizeof(int32_t); // ~256MB of int32_t data
    samples = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    if (!samples) {
        exit(1);
    }
    for (int j = 0; j < nb_samples; j++) {
        samples[j] = ((int32_t)rand()) << 8;
    }
    shift = 4;
    i = 0;
}