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
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
INT32 z2;

DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

static DCTELEM *data_buffer;
static DCTELEM *ws_buffer;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024 / sizeof(DCTELEM); // ~256MB total for both arrays
    data_buffer = (DCTELEM*)aligned_alloc(64, data_size * sizeof(DCTELEM));
    ws_buffer   = (DCTELEM*)aligned_alloc(64, data_size * sizeof(DCTELEM));

    if (!data_buffer || !ws_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
        ws_buffer[i]   = (DCTELEM)((i + 37) % 256 - 128);
    }

    dataptr = data_buffer;
    wsptr = ws_buffer;
}

void cleanup_vars() {
    if (data_buffer) free(data_buffer);
    if (ws_buffer) free(ws_buffer);
}