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

static uint8_t src1_buffer[256 * 1024 * 10]; // ~25.6 MB to allow sufficient stride and offset access
static int16_t tmp_buffer[8 * 10005];      // Enough for h+5 iterations, each storing 8 int16_t

void init_vars() {
    srcStride = 16; // Stride greater than kernel width to simulate 2D stepping
    src1 = src1_buffer + 10; // Offset to allow negative indexing from -2 safely
    tmp = tmp_buffer;

    // Initialize src1 base region to prevent undefined behavior in computation
    memset(src1 - 10, 1, sizeof(src1_buffer) - 20);

    // Ensure tmp memory is accessible
    memset(tmp_buffer, 0, sizeof(tmp_buffer));
}