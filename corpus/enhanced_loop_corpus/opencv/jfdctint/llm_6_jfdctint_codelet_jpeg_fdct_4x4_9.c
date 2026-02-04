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
    INT32 t0, t1, t10, t11;
    t0 = dataptr[8 * 0] + dataptr[8 * 3];
    t1 = dataptr[8 * 1] + dataptr[8 * 2];
    t10 = dataptr[8 * 0] - dataptr[8 * 3];
    t11 = dataptr[8 * 1] - dataptr[8 * 2];

    INT32 sum_even = (t0 + ((INT32)1) << (2 - 1));
    INT32 sum_odd = t1;

    dataptr[8 * 0] = (DCTELEM)((sum_even + sum_odd) >> 2);
    dataptr[8 * 2] = (DCTELEM)((sum_even - sum_odd) >> 2);

    INT32 temp_sum_diff = t10 + t11;
    INT32 scaled = temp_sum_diff * ((INT32)4433);
    INT32 adjusted = scaled + (((INT32)1) << (13 + 2 - 1));

    dataptr[8 * 1] = (DCTELEM)((adjusted + t10 * ((INT32)6270)) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)((adjusted - t11 * ((INT32)15137)) >> (13 + 2));

    dataptr++;
}
}
