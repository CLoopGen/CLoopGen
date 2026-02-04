#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t *ref;
int16_t *src;
int16_t *dst;
int len;
int i;

void init_vars() {
    const size_t data_size = 64 * (1 << 20); // ~64 MB of total data (adjustable)
    len = data_size / sizeof(int16_t);      // Number of int16_t elements

    ref = aligned_alloc(32, len * sizeof(int16_t));
    src = aligned_alloc(32, len * sizeof(int16_t));
    dst = aligned_alloc(32, len * sizeof(int16_t));

    if (!ref || !src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; ++j) {
        ref[j] = rand() % 1000;
        src[j] = rand() % 1000;
        dst[j] = rand() % 1000;
    }
}