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
    tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    z1 = (JLONG)wsptr[2];
    z2 = (JLONG)wsptr[4];
    z3 = (JLONG)wsptr[6];
    tmp3 = ((z3) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = tmp0 + tmp3;
    tmp2 = tmp0 - tmp3 - tmp3;
    tmp0 = ((z1 - z2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp11 = tmp2 + tmp0;
    tmp14 = tmp2 - tmp0 - tmp0;
    tmp0 = ((z1 + z2) * (((JLONG)((1.3289260490000001) * (((JLONG)1) << 13) + 0.5))));
    tmp2 = ((z1) * (((JLONG)((1.0833504410000001) * (((JLONG)1) << 13) + 0.5))));
    tmp3 = ((z2) * (((JLONG)((0.245575608) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp1 + tmp0 - tmp3;
    tmp12 = tmp1 - tmp0 + tmp2;
    tmp13 = tmp1 - tmp2 + tmp3;
    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    z4 = (JLONG)wsptr[7];
    z2 = ((z2) * (-((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
    tmp2 = ((z1 + z3) * (((JLONG)((0.90903895499999998) * (((JLONG)1) << 13) + 0.5))));
    tmp3 = ((z1 + z4) * (((JLONG)((0.48368952500000001) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = tmp2 + tmp3 - z2;
    tmp1 = ((z3 - z4) * (((JLONG)((1.392728481) * (((JLONG)1) << 13) + 0.5))));
    tmp2 += z2 - tmp1;
    tmp3 += z2 + tmp1;
    tmp1 = ((z1 - z3 - z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));

    if ((ctr & 1) == 0) {
        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[8] = range_limit[(int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((tmp11 - tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    } else {
        outptr[2] = range_limit[(int)((tmp12 + tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)((tmp12 - tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)((tmp13 + tmp3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)((tmp13 - tmp3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    }
    outptr[4] = range_limit[(int)((tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];

    wsptr += 8;
}
}
