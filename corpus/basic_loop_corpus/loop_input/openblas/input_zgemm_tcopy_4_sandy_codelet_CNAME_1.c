#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG col;
BLASLONG i;
BLASLONG ii;
float *src0;
float *src1;
float *dest0;

static float *src0_buffer;
static float *src1_buffer;
static float *dest_buffer;

void init_vars() {
    // Set problem size to get around 0.01s runtime on modern CPU
    // Based on typical performance, aim for ~64-128MB of data processed
    row = 1024;
    col = 32768;  // Must be divisible by 4

    size_t src0_size = (col / 4) * 8 * sizeof(float);
    size_t src1_size = (col / 4) * 8 * sizeof(float);
    size_t dest_size = (col / 4) * (row << 3) * sizeof(float);

    // Allocate buffers with padding to prevent out-of-bounds access
    src0_buffer = (float*)aligned_alloc(32, src0_size + 64);
    src1_buffer = (float*)aligned_alloc(32, src1_size + 64);
    dest_buffer = (float*)aligned_alloc(32, dest_size + 128);

    // Initialize pointers
    src0 = src0_buffer;
    src1 = src1_buffer;
    dest0 = dest_buffer;

    // Initialize input data
    for (size_t j = 0; j < src0_size / sizeof(float); j++) {
        src0_buffer[j] = 1.0f + (j % 1000) * 0.001f;
    }
    for (size_t j = 0; j < src1_size / sizeof(float); j++) {
        src1_buffer[j] = 2.0f + (j % 1000) * 0.001f;
    }
    // Clear destination to avoid undefined behavior
    memset(dest_buffer, 0, dest_size);
}