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
INT32 indices[4] = {0, 8, 16, 24};
for (ctr = 0; ctr < 4; ctr++) {
    INT32 idx = indices[ctr];
    tmp0 = dataptr[idx + 0] + dataptr[idx + 24] + (((INT32)1) << (2 - 1));
    tmp1 = dataptr[idx + 8] + dataptr[idx + 16];
    tmp10 = dataptr[idx + 0] - dataptr[idx + 24];
    tmp11 = dataptr[idx + 8] - dataptr[idx + 16];
    dataptr[idx + 0] = (DCTELEM)((tmp0 + tmp1) >> (2));
    dataptr[idx + 16] = (DCTELEM)((tmp0 - tmp1) >> (2));
    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp0 += ((INT32)1) << (13 + 2 - 1);
    dataptr[idx + 8] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 + 2));
    dataptr[idx + 24] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 + 2));
}
}
