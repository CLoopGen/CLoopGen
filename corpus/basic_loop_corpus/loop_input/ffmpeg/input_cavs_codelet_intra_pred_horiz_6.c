#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
uint8_t *left;
ptrdiff_t stride;
int y;
uint64_t a;

static uint8_t *d_storage;
static uint8_t *left_storage;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of output data
    stride = 8; // Each write is 8 bytes, so stride matches natural alignment

    d_storage = aligned_alloc(64, data_size);
    left_storage = aligned_alloc(64, 16); // Need at least 9 elements (y+1 up to 8)

    if (!d_storage || !left_storage) {
        exit(1);
    }

    d = d_storage;
    left = left_storage;

    // Initialize left with non-zero values to ensure meaningful computation
    for (int i = 0; i < 16; i++) {
        left[i] = (uint8_t)(i + 1);
    }

    y = 0;
    a = 0;
}