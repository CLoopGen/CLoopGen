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
for (ctr = 16 - 1; ctr >= 0; ctr -= 2) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 3] + (((INT32)1) << (2 - 1));
    tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
    tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
    dataptr[8 * 0] = (DCTELEM)((tmp0 + tmp1) >> 2);
    dataptr[8 * 2] = (DCTELEM)((tmp0 - tmp1) >> 2);
    tmp0 = ((tmp10 + tmp11) * 4433LL) >> 1;
    tmp1 = ((tmp10 - tmp11) * 3135LL) >> 1;
    tmp0 += ((INT32)1) << (12 + 2 - 1);
    dataptr[8 * 1] = (DCTELEM)((tmp0 + tmp1 + (tmp10 * 6270LL)) >> (12 + 2));
    dataptr[8 * 3] = (DCTELEM)((tmp0 - tmp1 - (tmp11 * 15137LL)) >> (12 + 2));

    if (ctr > 0) {
        DCTELEM *next_dataptr = dataptr + 1;
        INT32 tmp0b = next_dataptr[8 * 0] + next_dataptr[8 * 3] + (((INT32)1) << (2 - 1));
        INT32 tmp1b = next_dataptr[8 * 1] + next_dataptr[8 * 2];
        INT32 tmp10b = next_dataptr[8 * 0] - next_dataptr[8 * 3];
        INT32 tmp11b = next_dataptr[8 * 1] - next_dataptr[8 * 2];
        next_dataptr[8 * 0] = (DCTELEM)((tmp0b + tmp1b) >> 2);
        next_dataptr[8 * 2] = (DCTELEM)((tmp0b - tmp1b) >> 2);
        tmp0b = ((tmp10b + tmp11b) * 4433LL) >> 1;
        tmp0b += ((INT32)1) << (12 + 2 - 1);
        next_dataptr[8 * 1] = (DCTELEM)((tmp0b + (tmp10b * 6270LL)) >> (12 + 2));
        next_dataptr[8 * 3] = (DCTELEM)((tmp0b - (tmp11b * 15137LL)) >> (12 + 2));
    }
    dataptr += 2;
}
}
