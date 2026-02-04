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
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 z1;
INT32 z2;

DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

static DCTELEM *data_buffer;
static DCTELEM *ws_buffer;

void init_vars() {
    const size_t total_elements = (1 << 20) * 8; // ~8MB of DCTELEM data (each DCTELEM is typically 4 bytes -> ~32MB total)
    data_buffer = (DCTELEM *)calloc(total_elements, sizeof(DCTELEM));
    ws_buffer = (DCTELEM *)calloc(total_elements, sizeof(DCTELEM));

    if (!data_buffer || !ws_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
        ws_buffer[i] = (DCTELEM)((i * 3) % 256 - 128);
    }

    dataptr = data_buffer;
    wsptr = ws_buffer;
}