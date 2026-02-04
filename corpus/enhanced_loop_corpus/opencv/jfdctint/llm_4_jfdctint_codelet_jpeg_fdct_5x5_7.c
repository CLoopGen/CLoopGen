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
for (ctr = 0; ctr < 5; ctr++) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 3];
    tmp2 = dataptr[8 * 2];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = dataptr[8 * 0] - dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] - dataptr[8 * 3];

    INT32 t0 = (((tmp10 + tmp2) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5)))));
    INT32 t1 = ((tmp11) * (((INT32)((1.011928851) * (((INT32)1) << 13) + 0.5))));
    INT32 t2 = ((tmp10 - (tmp2 << 2)) * (((INT32)((0.45254833999999999) * (((INT32)1) << 13) + 0.5))));
    INT32 t3 = ((tmp0 + tmp1) * (((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5))));
    INT32 t4 = ((tmp0) * (((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5))));
    INT32 t5 = ((tmp1) * (((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 0] = (DCTELEM)(((t0 + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2)));
    dataptr[8 * 2] = (DCTELEM)(((t1 + t2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 4] = (DCTELEM)(((t1 - t2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 1] = (DCTELEM)(((t3 + t4) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)(((t3 - t5) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    dataptr++;
}
}
