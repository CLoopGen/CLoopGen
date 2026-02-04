#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *ptr;
ptrdiff_t a_stride;
ptrdiff_t b_stride;
int quant;
int i;
int t;
int p0;
int p1;
int p2;
int p3;
int p4;
int p5;
int p6;
int p7;
int p8;
int p9;
int ql;

static uint8_t *buffer;
static size_t total_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime

void init_vars() {
    quant = 4;
    ql = 2;
    a_stride = 16;
    b_stride = 1;

    // Allocate buffer with margin to prevent out-of-bounds access
    // We access from -5*a_stride to +4*a_stride => need at least 10*a_stride width
    // And 8 rows due to loop count
    size_t row_size = 32;
    size_t rows = 16;
    total_size = row_size * rows;
    
    buffer = (uint8_t*)aligned_alloc(64, total_size);
    if (!buffer) exit(1);

    // Initialize buffer with pseudo-random data
    for (size_t i = 0; i < total_size; i++) {
        buffer[i] = (uint8_t)((i * 17 + 13) % 251);
    }

    // Set initial ptr to middle of buffer to allow negative offsets
    ptr = buffer + (row_size * 5) + 10; // safe starting point with room for -5*a_stride
}