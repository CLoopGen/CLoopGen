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
INT32 z1;
INT32 z2;
INT32 z3;

DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

static DCTELEM data_array[8 * 32768];
static DCTELEM ws_array[8 * 32768];

void init_vars() {
    for (int i = 0; i < 8 * 32768; i++) {
        data_array[i] = (DCTELEM)(i % 257 - 128);
        ws_array[i] = (DCTELEM)((i * 7) % 257 - 128);
    }
    dataptr = data_array;
    wsptr = ws_array;
    ctr = 8 - 1;
}