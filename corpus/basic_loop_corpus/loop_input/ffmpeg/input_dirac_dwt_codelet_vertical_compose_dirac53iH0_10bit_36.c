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
    // Aim for approximately 64MB of total data (3 arrays of int32_t)
    // Each int32_t is 4 bytes, so 64MB / (3 * 4) = ~5.33M elements per array
    size_t num_elements = 1 << 23; // 8,388,608 elements (~32MB per array, ~96MB total)
    width = (int)num_elements;

    b0 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));

    for (size_t idx = 0; idx < num_elements; idx++) {
        b0[idx] = (int32_t)(idx % 1000);
        b1[idx] = (int32_t)((idx + 500) % 1500);
        b2[idx] = (int32_t)((idx + 100) % 2000);
    }
}