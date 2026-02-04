#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW outptr;
JSAMPROW inptr;
JDIMENSION col;
JDIMENSION num_cols;

static JSAMPLE *in_buffer;
static JSAMPLE *out_buffer;
static size_t total_in_size;
static size_t total_out_size;

void init_vars() {
    // Aim for approximately 64MB of input data to ensure loop takes ~0.01s
    total_in_size = 64 * (1 << 20); // 64 MB
    total_out_size = total_in_size * 3; // Each input produces 3 outputs

    in_buffer = (JSAMPLE*)aligned_alloc(32, total_in_size);
    out_buffer = (JSAMPLE*)aligned_alloc(32, total_out_size);

    if (!in_buffer || !out_buffer) {
        exit(1);
    }

    // Initialize input data with non-zero pattern
    for (size_t i = 0; i < total_in_size; i++) {
        in_buffer[i] = (JSAMPLE)(i % 251);
    }
    
    // Clear output buffer
    for (size_t i = 0; i < total_out_size; i++) {
        out_buffer[i] = 0;
    }

    inptr = in_buffer;
    outptr = out_buffer;
    num_cols = (JDIMENSION)total_in_size;
    col = 0;
}