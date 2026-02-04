#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp10;
INT32 tmp11;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static size_t num_elements;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    num_elements = data_size / sizeof(DCTELEM);
    
    // Ensure num_elements is at least 4 for safe access in loop
    if (num_elements < 4) {
        num_elements = 4;
        data_size = num_elements * sizeof(DCTELEM);
    }

    data_buffer = (DCTELEM*)calloc(num_elements, sizeof(DCTELEM));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize with non-zero values to ensure meaningful computation
    for (size_t i = 0; i < num_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 256);
    }

    dataptr = data_buffer;
    ctr = 0;
    tmp0 = 0;
    tmp1 = 0;
    tmp10 = 0;
    tmp11 = 0;
}