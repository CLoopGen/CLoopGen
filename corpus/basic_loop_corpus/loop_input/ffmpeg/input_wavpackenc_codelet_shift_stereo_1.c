#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *left;
int32_t *right;
int nb_samples;
int shift;
int i;

void init_vars() {
    nb_samples = 32 * 1024 * 1024 / sizeof(int32_t); // ~128MB of total data for both arrays
    shift = 2;

    left = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));
    right = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    if (!left || !right) {
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        left[j] = (int32_t)(j * 5 + 1);
        right[j] = (int32_t)(j * 7 - 3);
    }
}