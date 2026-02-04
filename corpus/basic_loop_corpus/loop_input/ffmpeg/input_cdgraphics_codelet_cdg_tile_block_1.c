#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *data;
int b;
unsigned int ci;
unsigned int ri;
int color;
int x;
int y;
int ai;
int stride;
uint8_t *buf;

void init_vars() {
    // Allocate data with size to cover index [4 + 11] = 15, so at least 16 bytes
    data = (uint8_t*)calloc(16, sizeof(uint8_t));
    // Initialize data[0] and data[1] to ensure defined color values
    data[0] = 0xAA; // arbitrary: bits set so (data[0] & 15) = 10
    data[1] = 0x55; // (data[1] & 15) = 5
    // Set remaining data[4..15] to non-zero to allow bit testing
    for (int i = 4; i < 16; i++) {
        data[i] = 0xFF;
    }

    b = 1; // enable the XOR condition

    ci = 0;
    ri = 0;
    stride = 6; // ensures ai indexing aligns with buf layout

    // buf must be large enough to handle access at:
    // ai = ci + x + stride*(ri + y), where x in [0,5], y in [0,11]
    // => max index: 0 + 5 + 6*(0 + 11) = 5 + 66 = 71
    // We'll allocate more than needed to simulate larger dataset
    // Target ~64MB buffer to dominate execution time around 0.01s on modern CPU
    // But note: loop runs only 12*6 = 72 iterations — very fast.
    // To make runtime ~0.01s, we don't need big data; but problem says "unless length specified"
    // Since no explicit size given, choose buf size such that memory effects are measurable.
    // However, the instruction says: "suggest 1MB–256MB", so pick 16MB to be in range.

    size_t buf_size = 16 * 1024 * 1024; // 16 MB
    buf = (uint8_t*)calloc(buf_size, sizeof(uint8_t));
    if (!buf) {
        exit(1);
    }

    // Ensure no out-of-bounds: maximum ai computed as:
    // ai = ci + x + stride*(ri + y)
    //   = 0 + 5 + 6*(0 + 11) = 71, which is << 16MB, so safe.

    // Initialize some buf content if needed
    for (int i = 0; i < 100; i++) {
        buf[i] = i ^ 0x7F;
    }
}