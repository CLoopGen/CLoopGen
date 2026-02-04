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
for (ctr = 0; ctr < 8; ctr++) {
    tmp0 = dataptr[0] + dataptr[4];
    tmp1 = dataptr[1] + dataptr[3];
    tmp2 = dataptr[2];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = dataptr[0] - dataptr[4];
    tmp1 = dataptr[1] - dataptr[3];
    dataptr[0] = (DCTELEM)(((((tmp10 + tmp2) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp11 = ((tmp11) * (((INT32)((1.011928851) * (((INT32)1) << 13) + 0.5))));
    tmp10 -= tmp2 << 2;
    tmp10 = ((tmp10) * (((INT32)((0.45254833999999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp10 = ((tmp0 + tmp1) * (((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5))));
    dataptr[1] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[3] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr += 8;
}
}
