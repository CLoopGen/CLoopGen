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
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ctr++) {
    INT32 d0 = dataptr[8 * 0], d1 = dataptr[8 * 1], d2 = dataptr[8 * 2];
    INT32 d3 = dataptr[8 * 3], d4 = dataptr[8 * 4], d5 = dataptr[8 * 5];

    tmp0 = d0 + d5;
    tmp11 = d1 + d4;
    tmp2 = d2 + d3;
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;

    INT32 sub0 = d0 - d5;
    INT32 sub1 = d1 - d4;
    INT32 sub2 = d2 - d3;

    tmp0 = sub0;
    tmp1 = sub1;
    tmp2 = sub2;

    tmp10 = ((sub0 + sub2) * (((INT32)((0.65071182900000002) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 0] = (DCTELEM)(((((tmp10 + tmp11 + tmp10) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 2] = (DCTELEM)(((((tmp12) * (((INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 4] = (DCTELEM)(((((tmp10 - tmp11) * (((INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 1] = (DCTELEM)(((tmp10 + ((sub0 + sub1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)(((((sub0 - sub1 - sub2) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 5] = (DCTELEM)(((tmp10 + ((sub2 - sub1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    dataptr++;
}
}
