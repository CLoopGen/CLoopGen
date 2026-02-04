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

void init_vars() {
    data_size = 1 << 20;  // 1MB of data (~0.01 sec runtime estimate)
    data_buffer = (DCTELEM*)calloc(data_size, sizeof(DCTELEM));
    if (!data_buffer) {
        exit(1);
    }
    
    // Ensure at least 4 rows of 8 elements each are accessible
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }
    
    dataptr = data_buffer;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
// Caller must ensure cleanup if needed