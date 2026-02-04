#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp4;
INT32 tmp5;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;

DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

static DCTELEM *data_buffer;
static DCTELEM *ws_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    const size_t num_elements = data_size / sizeof(DCTELEM);
    
    // Allocate memory for dataptr and wsptr with padding to avoid out-of-bounds access
    data_buffer = (DCTELEM*)calloc(num_elements, sizeof(DCTELEM));
    ws_buffer = (DCTELEM*)calloc(num_elements, sizeof(DCTELEM));
    
    if (!data_buffer || !ws_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    // Initialize buffers with non-zero values to allow meaningful computation
    for (size_t i = 0; i < num_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
        ws_buffer[i] = (DCTELEM)((i * 7) % 256 - 128);
    }
    
    // Set pointers to middle of buffer so that 8*7 offset access stays in bounds
    size_t base_index = (num_elements / 2) & (~7); // Align to multiple of 8
    dataptr = &data_buffer[base_index];
    wsptr = &ws_buffer[base_index];
    
    // Initialize loop counter
    ctr = 8 - 1;
}