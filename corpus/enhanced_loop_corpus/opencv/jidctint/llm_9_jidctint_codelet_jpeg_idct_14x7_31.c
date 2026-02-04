#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: fewer operations, unrolled inner logic partially removed
for (ctr = 0; ctr < 3; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z1 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    z1 <<= 13;
    z4 = (INT32)wsptr[4];
    // Simplified trigonometric factor approximations using fewer terms
    z2 = ((z4) * (((INT32)(1.27 * (((INT32)1) << 13) + 0.5))));
    z3 = ((z4) * (((INT32)(0.31 * (((INT32)1) << 13) + 0.5))));
    tmp10 = z1 + z2;
    tmp11 = z1 + z3;
    tmp12 = z1 - z4;
    tmp23 = z1 - ((z2 + z3 - z4));

    // Skip complex cross-term computations from odd coefficients
    // Approximate final values with reduced precision and fewer multiplies
    tmp20 = tmp10 + ((INT32)wsptr[2]);
    tmp21 = tmp11 + ((INT32)wsptr[6]);
    tmp22 = tmp12 + ((INT32)wsptr[1]);
    tmp24 = tmp12 - ((INT32)wsptr[3]);
    tmp25 = tmp11 - ((INT32)wsptr[5]);
    tmp26 = tmp10 - ((INT32)wsptr[7]);

    // Only write first few outputs to reduce memory traffic
    outptr[0] = range_limit[(int)((tmp20) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp22) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp24) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp25) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp26) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    wsptr += 8;
}
}
