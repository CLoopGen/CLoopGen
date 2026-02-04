#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
DCTELEM *dataptr;
int ctr;

static DCTELEM data_buffer[256 * 1024]; // ~1MB of DCT elements (256KB)

void init_vars() {
    for (int i = 0; i < 256 * 1024; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }
    dataptr = data_buffer;
}