#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int DCTELEM;
typedef long INT32;

DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z1;
DCTELEM z2;
DCTELEM z3;
DCTELEM z4;
DCTELEM z5;
DCTELEM z11;
DCTELEM z13;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB of data
    const size_t element_count = total_size / sizeof(DCTELEM);
    
    // Allocate aligned memory to avoid issues and improve performance
    data_buffer = (DCTELEM*)aligned_alloc(32, total_size);
    
    if (!data_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize buffer with non-zero values for meaningful computation
    for (size_t i = 0; i < element_count; i++) {
        data_buffer[i] = (DCTELEM)(i % 512 - 256); // Range [-256, 255]
    }
    
    // Set initial dataptr to start of buffer
    dataptr = data_buffer;
    
    // Ensure loop runs only over valid blocks
    // Each iteration consumes 8 elements
    size_t block_count = element_count / 8;
    if (block_count == 0) {
        ctr = 0;
    } else {
        // We want the loop to run many times (~0.01 sec), so use large block count
        // The loop decrements from 7 down to 0 per block, so we don't modify ctr here
        // Instead, we'll let the loop run on each 8-element block sequentially
        // Reset will be handled externally; just initialize first block
        ctr = 8 - 1;
    }
}