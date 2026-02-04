#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 64;
uint8_t *src0;
uint8_t *src1;
uint8_t *src2;
int H = 0;
int V = 0;

static uint8_t buffer[262144]; // 256 KB buffer to ensure sufficient data

void init_vars() {
    size_t i;

    src0 = buffer + 32768; // Point src0 to middle of buffer for safe indexing
    src1 = buffer + 98304;
    src2 = buffer + 163840;

    stride = 64;
    k = 0;
    H = 0;
    V = 0;

    // Initialize buffer with predictable values to avoid undefined behavior
    for (i = 0; i < sizeof(buffer); ++i) {
        buffer[i] = (uint8_t)(i & 0xFF);
    }
}