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
    width = 67108864; // Approximately 256MB of data (67M elements * 4 bytes * 3 arrays ≈ 256MB)

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    for (i = 0; i < width; i++) {
        b0[i] = (int32_t)(i % 100);
        b1[i] = (int32_t)((i + 1) % 100);
        b2[i] = (int32_t)((i + 2) % 100);
    }
}