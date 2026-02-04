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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 14; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Reorder independent calculations to eliminate some loop-carried false dependencies
    // and introduce parallel evaluation where possible.

    // Pre-load and pre-compute values that are used later but do not depend on prior writes in this iteration
    INT32 w0 = (INT32)wsptr[0];
    INT32 w1 = (INT32)wsptr[1];
    INT32 w2 = (INT32)wsptr[2];
    INT32 w3 = (INT32)wsptr[3];
    INT32 w4 = (INT32)wsptr[4];
    INT32 w5 = (INT32)wsptr[5];
    INT32 w6 = (INT32)wsptr[6];

    tmp23 = w0 + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    tmp23 <<= 13;

    // First group: even indices (w2, w4, w6)
    z1 = w2; z2 = w4; z3 = w6;
    tmp20 = ((z2 - z3) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
    tmp22 = ((z1 - z2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
    tmp21 = tmp20 + tmp22 + tmp23 - (z2 * (((INT32)((1.841218003) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z1 + z3;
    z2 -= tmp10;
    tmp10 = (tmp10 * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + tmp23;
    tmp20 += tmp10 - (z3 * (((INT32)((0.077722535999999995) * (((INT32)1) << 13) + 0.5))));
    tmp22 += tmp10 - (z1 * (((INT32)((2.4706022490000001) * (((INT32)1) << 13) + 0.5))));
    tmp23 += (z2 * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

    // Second group: odd indices (w1, w3, w5), now computed independently without interfering with first group
    z1 = w1; z2 = w3; z3 = w5;
    INT32 tmp11_odd = ((z1 + z2) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
    INT32 tmp12_odd = ((z1 - z2) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
    INT32 tmp10_odd = tmp11_odd - tmp12_odd;
    tmp11_odd += tmp12_odd;
    tmp12_odd = ((z2 + z3) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
    tmp11_odd += tmp12_odd;
    z2 = ((z1 + z3) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
    tmp10_odd += z2;
    tmp12_odd += z2 + (z3 * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));

    // Final stores using combined results
    outptr[0] = range_limit[(int)((tmp20 + tmp10_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[6] = range_limit[(int)((tmp20 - tmp10_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21 + tmp11_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp21 - tmp11_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp22 + tmp12_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp22 - tmp12_odd) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)(tmp23 >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    wsptr += 7;
}
}
