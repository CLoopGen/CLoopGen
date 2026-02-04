#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride;
unsigned char *cp;
tmsize_t i;

static unsigned char *data_buffer;

void init_vars() {
    // Allocate 64MB of data to ensure loop runs for noticeable time (~0.01 sec on modern CPU)
    const size_t data_size = 64 << 20; // 64 * 2^20 = 64MB
    data_buffer = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize cp to point near the end of the buffer to allow decrementing and indexing by stride
    stride = 1024;
    cp = data_buffer + data_size - 1;

    // Ensure that during the loop: cp[stride] and cp[0] are valid
    // We require: cp >= data_buffer + stride (so cp[stride] is valid when cp is decremented down to data_buffer + stride)
    // So set initial cp so after (stride - 4) decrements, it doesn't go below data_buffer + stride
    // => initial_cp - (stride - 4) >= data_buffer + stride
    // => initial_cp >= data_buffer + 2 * stride - 4
    // Choose initial cp = data_buffer + 2 * stride - 4 + 100 (for safety margin)
    cp = data_buffer + 2 * stride - 4 + 100;

    // Initialize data in the region accessed by the loop
    for (size_t idx = 0; idx < (size_t)(cp + 1 - data_buffer + stride); idx++) {
        data_buffer[idx] = (unsigned char)(idx & 255);
    }
}