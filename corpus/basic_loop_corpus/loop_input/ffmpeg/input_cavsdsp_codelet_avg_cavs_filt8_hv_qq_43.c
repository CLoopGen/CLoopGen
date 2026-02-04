#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h = 10000;
int i;

static uint8_t src1_buffer[256 * 1024 * 1024 + 12]; // large buffer with padding for safe access
static int16_t tmp_buffer[256 * 1024 * 1024 / 8 * 8]; // roughly matching tmp size

void init_vars() {
    srcStride = 8;
    src1 = src1_buffer + 2; // offset to allow -2 indexing at start
    tmp = tmp_buffer;

    // Initialize src1 base region with non-zero values to avoid trivial optimization
    for (size_t j = 0; j < sizeof(src1_buffer); ++j) {
        src1_buffer[j] = (uint8_t)(j % 251);
    }

    // Clear tmp region
    memset(tmp_buffer, 0, sizeof(tmp_buffer));
}