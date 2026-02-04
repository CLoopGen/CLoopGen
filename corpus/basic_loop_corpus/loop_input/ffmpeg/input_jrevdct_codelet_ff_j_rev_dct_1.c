#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t tmp0;
int32_t tmp1;
int32_t tmp2;
int32_t tmp3;
int32_t tmp10;
int32_t tmp11;
int32_t tmp12;
int32_t tmp13;
int32_t z1;
int32_t z2;
int32_t z3;
int32_t z4;
int32_t z5;
int32_t d0;
int32_t d1;
int32_t d2;
int32_t d3;
int32_t d4;
int32_t d5;
int32_t d6;
int32_t d7;
int16_t *dataptr;
int rowctr;

static int16_t *data_buffer;

void init_vars() {
    const size_t total_size = 1 << 24; // 16 MB of data to ensure ~0.01s runtime
    data_buffer = (int16_t*)aligned_alloc(32, total_size);
    if (!data_buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values to trigger various code paths in the loop
    for (size_t i = 0; i < total_size / sizeof(int16_t); i++) {
        data_buffer[i] = (int16_t)(i & 0xFF);
    }

    dataptr = data_buffer;
    rowctr = 8 - 1;
}

// Ensure cleanup if needed (though not called here)
// Caller is responsible for freeing via free(dataptr) if necessary.