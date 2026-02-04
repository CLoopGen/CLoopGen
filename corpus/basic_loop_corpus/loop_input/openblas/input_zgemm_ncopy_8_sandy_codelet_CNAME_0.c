#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG col;
float *src;
BLASLONG srcdim;
float *dest;
BLASLONG i;
BLASLONG j;
BLASLONG ii;
float *src0;
float *src1;
float *src2;
float *src3;
float *src4;
float *src5;
float *src6;
float *src7;
float *dest0;

static float *src_buffer;
static float *dest_buffer;
static BLASLONG buffer_size = 1 << 20; // ~4MB per buffer (floats)

void init_vars() {
    // Set dimensions to ensure loop runs with valid bounds
    row = 1024;  // Must be multiple of 4, plus possible 2 or 1 remainder
    col = 1024; // Must be multiple of 8

    srcdim = row;

    // Allocate large enough buffers to prevent out-of-bounds access
    src_buffer = (float*)__builtin_malloc(buffer_size * sizeof(float) * 8);
    dest_buffer = (float*)__builtin_malloc(buffer_size * sizeof(float) * 8);

    src = src_buffer;
    dest = dest_buffer;

    // Initialize source data to avoid undefined behavior
    for (BLASLONG k = 0; k < buffer_size * 8; ++k) {
        src_buffer[k] = (float)(k % 1000) / 100.0f;
    }

    // Zero destination to have defined output
    for (BLASLONG k = 0; k < buffer_size * 8; ++k) {
        dest_buffer[k] = 0.0f;
    }

    // Ensure that all intermediate pointers are NULL initially (will be set in loop)
    src0 = src1 = src2 = src3 = src4 = src5 = src6 = src7 = NULL;
    dest0 = NULL;
    i = j = ii = 0;
}