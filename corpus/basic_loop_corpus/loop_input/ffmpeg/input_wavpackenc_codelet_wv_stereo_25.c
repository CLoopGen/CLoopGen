#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples_l;
int32_t *samples_r;
int nb_samples;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB total for two arrays

    samples_l = aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = aligned_alloc(32, nb_samples * sizeof(int32_t));

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = 0;
        samples_r[j] = 0;
    }

    // Set a non-zero value near the end to ensure loop runs most iterations
    samples_l[nb_samples - 1] = 1;
    samples_r[nb_samples - 1] = 1;
}