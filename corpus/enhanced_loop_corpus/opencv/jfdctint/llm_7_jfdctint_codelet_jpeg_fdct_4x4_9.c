#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    INT32 base_val = dataptr[0];
    INT32 val1 = dataptr[8];
    INT32 val2 = dataptr[16];
    INT32 val3 = dataptr[24];

    INT32 tmp0 = base_val + val3;
    INT32 tmp1 = val1 + val2;
    INT32 tmp10 = base_val - val3;
    INT32 tmp11 = val1 - val2;

    tmp0 += ((INT32)1) << (2 - 1);

    DCTELEM out0 = (DCTELEM)((tmp0 + tmp1) >> 2);
    DCTELEM out2 = (DCTELEM)((tmp0 - tmp1) >> 2);

    INT32 intermediate = (tmp10 + tmp11) * 4433;
    intermediate += ((INT32)1) << (13 + 2 - 1);

    DCTELEM out1 = (DCTELEM)((intermediate + tmp10 * 6270) >> (13 + 2));
    DCTELEM out3 = (DCTELEM)((intermediate - tmp11 * 15137) >> (13 + 2));

    dataptr[8 * 0] = out0;
    dataptr[8 * 1] = out1;
    dataptr[8 * 2] = out2;
    dataptr[8 * 3] = out3;

    dataptr++;
}
}
