#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;
typedef long JLONG;

static JSAMPLE *in_buffer;
static JSAMPLE *out_buffer;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
JLONG rgb;
unsigned int g;

void init_vars() {
    // Allocate approximately 128MB of input data to target ~0.01s runtime
    // Each iteration consumes 2 bytes and produces 4 bytes
    size_t input_size_bytes = 134217728; // ~128MB
    size_t element_count = input_size_bytes / sizeof(JSAMPLE);
    
    // Ensure num_cols is even so that (num_cols >> 1) iterations read exactly 2 per loop
    num_cols = element_count & ~1U; // Round down to even number
    
    // Allocate input and output buffers
    in_buffer = (JSAMPLE*)aligned_alloc(64, num_cols * sizeof(JSAMPLE));
    out_buffer = (JSAMPLE*)aligned_alloc(64, num_cols * 2 * sizeof(JSAMPLE)); // 2 bytes in -> 4 bytes out per pair
    
    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    // Initialize input data with non-zero pattern for better testing
    for (JDIMENSION i = 0; i < num_cols; i++) {
        in_buffer[i] = (JSAMPLE)(i * 71 + 17); // Prime-based pattern
    }
    
    // Initialize pointers
    inptr = in_buffer;
    outptr = out_buffer;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
void cleanup_vars() {
    if (in_buffer) free(in_buffer);
    if (out_buffer) free(out_buffer);
}