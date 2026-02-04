#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 10; ctr++) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 3];
    tmp2 = dataptr[8 * 2];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = dataptr[8 * 0] - dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] - dataptr[8 * 3];

    INT32 factor1 = (((INT32)((1.28) * (((INT32)1) << 13) + 0.5)));
    INT32 factor2 = (((INT32)((1.011928851) * (((INT32)1) << 13) + 0.5)));
    INT32 factor3 = (((INT32)((0.45254833999999999) * (((INT32)1) << 13) + 0.5)));
    INT32 factor4 = (((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5)));
    INT32 factor5 = (((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5)));
    INT32 factor6 = (((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5)));

    INT32 sum0 = tmp10 + tmp2;
    INT32 scaled_sum0 = (sum0 * factor1 + ((INT32)1 << (14))) >> 15;
    dataptr[8 * 0] = (DCTELEM)scaled_sum0;

    tmp11 = (tmp11 * factor2);
    tmp10 -= tmp2 << 2;
    tmp10 = (tmp10 * factor3);

    INT32 combined1 = tmp11 + tmp10;
    INT32 combined2 = tmp11 - tmp10;
    dataptr[8 * 2] = (DCTELEM)((combined1 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 4] = (DCTELEM)((combined2 + ((INT32)1 << 14)) >> 15);

    tmp10 = (tmp0 + tmp1) * factor4;
    INT32 term1 = tmp0 * factor5;
    INT32 term2 = tmp1 * factor6;

    dataptr[8 * 1] = (DCTELEM)((tmp10 + term1 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 3] = (DCTELEM)((tmp10 - term2 + ((INT32)1 << 14)) >> 15);

    dataptr++;
}
}
