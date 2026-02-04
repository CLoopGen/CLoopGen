#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inbuf;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
int instride;

void init_vars() {
    // Set data size to achieve ~0.01s runtime - approx 64M elements should be sufficient
    num_cols = 64 * 1024 * 1024 / sizeof(JSAMPLE);
    
    // Ensure reasonable memory footprint (about 64-128MB total)
    if (num_cols > 64 * 1024 * 1024) {
        num_cols = 64 * 1024 * 1024;
    }
    
    instride = 1; // Access every element sequentially
    
    // Allocate input buffer with extra space for safe access
    inbuf = (JSAMPLE*)aligned_alloc(32, (size_t)(num_cols * instride + 1) * sizeof(JSAMPLE));
    
    // Allocate output buffer
    outptr = (JSAMPLE*)aligned_alloc(32, (size_t)num_cols * sizeof(JSAMPLE));
    
    // Initialize input pointer to start of buffer
    inptr = inbuf;
    
    // Initialize buffers to avoid undefined behavior
    for (JDIMENSION i = 0; i < num_cols * instride + 1; i++) {
        inbuf[i] = (JSAMPLE)(i & 0xFF);
    }
    for (JDIMENSION i = 0; i < num_cols; i++) {
        outptr[i] = 0;
    }
}

// External symbols referenced by loop()
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
int instride;