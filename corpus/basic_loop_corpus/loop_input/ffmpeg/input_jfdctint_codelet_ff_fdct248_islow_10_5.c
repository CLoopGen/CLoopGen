#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tmp0;
int tmp1;
int tmp2;
int tmp3;
int tmp4;
int tmp5;
int tmp6;
int tmp7;
int tmp10;
int tmp11;
int tmp12;
int tmp13;
int z1;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t total_elements;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of data
    total_elements = data_size / sizeof(int16_t);
    
    // Allocate aligned memory to ensure proper access
    if (posix_memalign((void**)&data_buffer, 32, data_size) != 0) {
        exit(1);
    }
    
    // Initialize buffer with non-zero values for meaningful computation
    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(i % 32768);
    }
    
    // Set dataptr to beginning of buffer
    dataptr = data_buffer;
    
    // Adjust loop counter so that we don't go out of bounds
    // Each iteration increments dataptr by 1, and we need at least 8 consecutive elements
    // So maximum safe iterations is total_elements / 8 - 1
    size_t max_iter = total_elements / 8;
    if (max_iter > 0) {
        ctr = (int)(max_iter - 1);
    } else {
        ctr = 0;
    }
}

// Cleanup function to avoid memory leaks (not required by problem but good practice)
void cleanup_vars() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}