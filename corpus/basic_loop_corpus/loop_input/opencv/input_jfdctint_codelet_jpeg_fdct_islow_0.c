#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef JLONG DCTELEM;

JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp4;
JLONG tmp5;
JLONG tmp6;
JLONG tmp7;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
JLONG z5;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB
    const size_t element_size = sizeof(DCTELEM);
    const size_t num_elements = total_size / element_size;

    // Allocate aligned buffer to avoid alignment issues
    if (posix_memalign((void**)&data_buffer, 64, total_size) != 0) {
        exit(1);
    }

    // Initialize all elements to non-zero predictable values to aid computation
    for (size_t i = 0; i < num_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 32768);
    }

    // Set dataptr to start of buffer
    dataptr = data_buffer;

    // Ensure loop runs over valid blocks of 8 elements
    // Adjust total size so we don't overrun in the loop
    // Each iteration processes 8 elements and advances by 8
    // We need at least 8 elements per block
    const size_t max_blocks = num_elements / 8;
    ctr = (int)(max_blocks - 1); // Start from max_blocks-1 down to 0
}

// Cleanup function to prevent memory leaks (not called here but implied usage)
// Freeing is not done here as loop may be called multiple times across program