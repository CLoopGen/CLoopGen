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
    tmp0 = dataptr[8 * 0] + dataptr[8 * 3];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
    tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
    tmp0 += tmp1;
    dataptr[8 * 0] = (DCTELEM)(tmp0 << 3);
    tmp0 -= (tmp1 << 1);
    dataptr[8 * 2] = (DCTELEM)(tmp0 << 2);
    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp1 = ((tmp10 - tmp11) * (((INT32)15137)));
    tmp0 += ((INT32)1) << (13 - 3 - 1);
    dataptr[8 * 1] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 - 3));
    dataptr[8 * 3] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 - 3));
    dataptr++;
}
}
