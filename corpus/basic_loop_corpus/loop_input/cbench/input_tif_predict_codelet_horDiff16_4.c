#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef int int32;
typedef int32 tsize_t;
typedef short int16;

tsize_t stride;
int16 *wp;
int i;

static int16 *wp_base;

void init_vars() {
    const size_t data_size = 64 * 1024 * sizeof(int16); // ~128KB of data
    wp_base = (int16*)malloc(data_size);
    if (!wp_base) {
        exit(1);
    }

    stride = 16384; // Must be > 4 to enter loop, and allows safe indexing
    wp = wp_base + stride - 1; // Adjust so that wp[stride] is initially valid

    // Initialize array elements to prevent undefined behavior
    for (size_t idx = 0; idx < 16384 + 4; idx++) {
        wp_base[idx] = (int16)(idx % 32768);
    }
}