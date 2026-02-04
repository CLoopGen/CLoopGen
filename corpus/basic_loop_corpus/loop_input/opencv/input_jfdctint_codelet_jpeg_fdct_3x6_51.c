#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer = NULL;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data (adjustable)
    const size_t row_size = 8 * 6; // we access indices 0 and 5, so need at least 6 elements per row

    data_buffer = (DCTELEM *)calloc(total_size, sizeof(DCTELEM));
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate data buffer\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128); // populate with sample values in range [-128, 127]
    }

    dataptr = data_buffer;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void free_vars() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}