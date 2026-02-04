#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int z2;
int z3;
int z4;
int z5;
int z11;
int z13;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t total_elements;

void init_vars() {
    const size_t target_size = 16 * 1024 * 1024; // ~16MB to ensure loop runs long enough
    const size_t element_size = sizeof(int16_t);
    total_elements = target_size / element_size;
    
    // Ensure total_elements is multiple of 8 for safe loop iteration
    total_elements = (total_elements / 8) * 8;
    
    data_buffer = (int16_t*)calloc(total_elements, element_size);
    if (!data_buffer) {
        exit(1);
    }
    
    // Initialize with non-zero pattern to make computation meaningful
    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(i % 32768);
    }
    
    dataptr = data_buffer;
}

// Cleanup function to prevent memory leaks (not required but good practice)
void cleanup_vars() {
    free(data_buffer);
    data_buffer = NULL;
}