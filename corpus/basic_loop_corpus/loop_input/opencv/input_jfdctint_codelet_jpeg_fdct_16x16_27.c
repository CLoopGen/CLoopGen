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
INT32 tmp6;
INT32 tmp7;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp16;
INT32 tmp17;

DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

static DCTELEM *data_buffer;
static DCTELEM *ws_buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    const size_t num_elements = total_size / sizeof(DCTELEM);
    
    data_buffer = (DCTELEM*)calloc(num_elements, sizeof(DCTELEM));
    ws_buffer = (DCTELEM*)calloc(num_elements, sizeof(DCTELEM));
    
    if (!data_buffer || !ws_buffer) {
        exit(1);
    }
    
    for (size_t i = 0; i < num_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 1024);
        ws_buffer[i] = (DCTELEM)((i + 512) % 1024);
    }
    
    dataptr = data_buffer;
    wsptr = ws_buffer;
    ctr = 8 - 1;
}