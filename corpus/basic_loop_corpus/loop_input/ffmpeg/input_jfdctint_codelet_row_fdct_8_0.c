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
unsigned int z1;
unsigned int z2;
unsigned int z3;
unsigned int z4;
unsigned int z5;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t total_elements;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of data
    total_elements = data_size / sizeof(int16_t);
    
    // Allocate aligned memory for better performance and alignment safety
    if (posix_memalign((void**)&data_buffer, 32, data_size) != 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-zero values to simulate real data
    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(i % 32768);
    }

    dataptr = data_buffer;
    ctr = 8 - 1;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void cleanup_vars() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}