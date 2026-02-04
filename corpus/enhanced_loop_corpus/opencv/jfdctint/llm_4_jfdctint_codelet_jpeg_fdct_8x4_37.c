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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    if (ctr % 2 == 0) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 3] + (((INT32)1) << (2 - 1));
        tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
        tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
        tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
        dataptr[8 * 0] = (DCTELEM)((tmp0 + tmp1) >> (2));
        dataptr[8 * 2] = (DCTELEM)((tmp0 - tmp1) >> (2));
    } else {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 3] + (((INT32)1) << (2 - 1));
        tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
        tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
        tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
        tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
        tmp0 += ((INT32)1) << (13 + 2 - 1);
        dataptr[8 * 1] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 + 2));
        dataptr[8 * 3] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 + 2));
    }
    dataptr++;
}
}
