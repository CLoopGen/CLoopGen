#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
int i;
int stride;
int map;
int hi;
int lo;

static uint8_t out_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    out = out_buffer;
    stride = 4;
    hi = 0xFF;
    lo = 0x00;
    i = 0;
    // Each iteration writes 4 bytes, total 4 iterations -> 16 bytes written
    // Ensure map has valid bits for all 4 iterations
    map = 0xABCD; // Example value with varying bits
}