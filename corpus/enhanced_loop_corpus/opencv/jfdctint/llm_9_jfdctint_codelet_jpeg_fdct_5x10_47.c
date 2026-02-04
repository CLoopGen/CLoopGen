#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: fewer operations, lower trip count, simplified expressions
for (ctr = 0; ctr < 3; ctr++) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 1];
    tmp1 = dataptr[8 * 1] + wsptr[8 * 0];
    tmp2 = dataptr[8 * 2] - dataptr[8 * 7];
    tmp3 = dataptr[8 * 3] - dataptr[8 * 6];
    tmp4 = dataptr[8 * 4] - dataptr[8 * 5];

    // Simplify transformation: reduce number of intermediate variables and combine steps
    tmp10 = tmp0 + tmp4;
    tmp11 = tmp1 - tmp3;

    // Approximate scaled fixed-point arithmetic with reduced precision (shift by 12 instead of 15)
    INT32 factor = ((INT32)(1.28 * (1 << 12)) + 0.5);

    dataptr[8 * 0] = (DCTELEM)(((tmp10 * factor) + (1 << 11)) >> 12);
    dataptr[8 * 1] = (DCTELEM)(((tmp11 * factor) + (1 << 11)) >> 12);

    // Skip complex cross terms and higher-order corrections
    // Only write two outputs per iteration to reduce computation
    // Remove all advanced trigonometric approximations

    // Minimal update of pointers
    dataptr++;
    wsptr++;
}
}
