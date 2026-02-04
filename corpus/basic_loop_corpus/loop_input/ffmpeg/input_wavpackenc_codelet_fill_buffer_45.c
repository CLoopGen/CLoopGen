#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int8_t *sptr;
int nb_samples;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024; // 64 million samples (~64MB input, ~128MB total)

    sptr = (int8_t *)aligned_alloc(32, nb_samples * sizeof(int8_t));
    dst = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    if (!sptr || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        sptr[j] = rand() % 256; // Fill with random bytes in range [0, 255]
    }

    i = 0;
}