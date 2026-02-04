#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
JLONG rgb;
unsigned int g;

static JSAMPLE *in_buffer = NULL;
static JSAMPLE *out_buffer = NULL;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // 64 MB of input data
    const size_t output_size = input_size / 2 * 4; // Each pair of input bytes produces 4-byte output

    in_buffer = (JSAMPLE*)aligned_alloc(32, input_size);
    out_buffer = (JSAMPLE*)aligned_alloc(32, output_size);

    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize input buffer with non-zero test pattern
    for (size_t i = 0; i < input_size; i++) {
        in_buffer[i] = (JSAMPLE)(i & 255);
    }

    // Clear output buffer
    for (size_t i = 0; i < output_size; i++) {
        out_buffer[i] = 0;
    }

    // Set up pointers and dimensions
    inptr = in_buffer;
    outptr = out_buffer;
    num_cols = (JDIMENSION)(input_size); // num_cols is used as byte count, loop uses >>1 so processes pairs
}