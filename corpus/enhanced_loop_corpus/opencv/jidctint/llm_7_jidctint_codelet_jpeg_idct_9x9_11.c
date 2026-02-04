#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 9; ctr++) {
    outptr = output_buf[ctr] + output_col;
    // Break some RAW dependencies by reordering independent computations
    // Load all wsptr values first to eliminate address calculation dependencies
    JLONG w0 = (JLONG)wsptr[0];
    JLONG w1 = (JLONG)wsptr[1];
    JLONG w2 = (JLONG)wsptr[2];
    JLONG w3 = (JLONG)wsptr[3];
    JLONG w4 = (JLONG)wsptr[4];
    JLONG w5 = (JLONG)wsptr[5];
    JLONG w6 = (JLONG)wsptr[6];
    JLONG w7 = (JLONG)wsptr[7];

    // Precompute constants outside variable chains where possible
    const JLONG c0707 = (JLONG)(0.70710678100000002 * ((JLONG)1 << 13) + 0.5);
    const JLONG c1328 = (JLONG)(1.3289260490000001 * ((JLONG)1 << 13) + 0.5);
    const JLONG c1083 = (JLONG)(1.0833504410000001 * ((JLONG)1 << 13) + 0.5);
    const JLONG c0245 = (JLONG)(0.245575608 * ((JLONG)1 << 13) + 0.5);
    const JLONG c1224 = (JLONG)(1.224744871 * ((JLONG)1 << 13) + 0.5);
    const JLONG c0909 = (JLONG)(0.90903895499999998 * ((JLONG)1 << 13) + 0.5);
    const JLONG c0483 = (JLONG)(0.48368952500000001 * ((JLONG)1 << 13) + 0.5);
    const JLONG c1392 = (JLONG)(1.392728481 * ((JLONG)1 << 13) + 0.5);

    tmp0 = (w0 + (((JLONG)1) << (1 + 2))) << 13;
    z1 = w2; z2 = w4; z3 = w6;
    tmp3 = z3 * c0707;
    tmp1 = tmp0 + tmp3;
    tmp2 = tmp0 - 2 * tmp3;
    tmp0 = (z1 - z2) * c0707;
    tmp11 = tmp2 + tmp0;
    tmp14 = tmp2 - 2 * tmp0;
    tmp0 = (z1 + z2) * c1328;
    tmp2 = z1 * c1083;
    tmp3 = z2 * c0245;
    tmp10 = tmp1 + tmp0 - tmp3;
    tmp12 = tmp1 - tmp0 + tmp2;
    tmp13 = tmp1 - tmp2 + tmp3;

    // Second half using w1, w3, w5, w7
    z1 = w1; z2 = w3; z3 = w5; z4 = w7;
    z2 = (z2) * (-c1224);
    tmp2 = (z1 + z3) * c0909;
    tmp3 = (z1 + z4) * c0483;
    tmp0 = tmp2 + tmp3 - z2;
    tmp1 = (z3 - z4) * c1392;
    tmp2 = tmp2 + z2 - tmp1;
    tmp3 = tmp3 + z2 + tmp1;
    tmp1 = (z1 - z3 - z4) * c1224;

    // Store results with reduced expression complexity
    int shift = 13 + 1 + 3;
    int mask = (255 * 4 + 3);
    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> shift) & mask];
    outptr[8] = range_limit[(int)((tmp10 - tmp0) >> shift) & mask];
    outptr[1] = range_limit[(int)((tmp11 + tmp1) >> shift) & mask];
    outptr[7] = range_limit[(int)((tmp11 - tmp1) >> shift) & mask];
    outptr[2] = range_limit[(int)((tmp12 + tmp2) >> shift) & mask];
    outptr[6] = range_limit[(int)((tmp12 - tmp2) >> shift) & mask];
    outptr[3] = range_limit[(int)((tmp13 + tmp3) >> shift) & mask];
    outptr[5] = range_limit[(int)((tmp13 - tmp3) >> shift) & mask];
    outptr[4] = range_limit[(int)(tmp14 >> shift) & mask];

    wsptr += 8;
}
}
