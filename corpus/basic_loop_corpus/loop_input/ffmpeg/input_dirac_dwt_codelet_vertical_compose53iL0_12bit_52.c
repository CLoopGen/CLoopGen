#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;

void init_vars() {
    width = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB total for three arrays

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1 || !b2) {
        exit(1);
    }

    for (i = 0; i < width; i++) {
        b0[i] = (int32_t)(i % 1000);
        b1[i] = (int32_t)((i + 100) % 1000);
        b2[i] = (int32_t)((i + 200) % 1000);
    }
}