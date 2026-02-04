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
    const size_t buffer_size = 256 * 1024; // ~1MB total (each element is 4 bytes)
    
    data_buffer = (DCTELEM*)aligned_alloc(32, buffer_size * sizeof(DCTELEM));
    ws_buffer   = (DCTELEM*)aligned_alloc(32, buffer_size * sizeof(DCTELEM));
    
    if (!data_buffer || !ws_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
        ws_buffer[i]   = (DCTELEM)((i * 7) % 256 - 128);
    }

    dataptr = data_buffer;
    wsptr = ws_buffer;
}