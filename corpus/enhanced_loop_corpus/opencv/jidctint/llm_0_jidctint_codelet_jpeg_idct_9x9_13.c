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
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
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
for (int depth = 0; depth < 3; depth++) {
    for (ctr = 0; ctr < 3; ctr++) {
        outptr = output_buf[depth * 3 + ctr] + output_col;
        tmp0 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp0 <<= 13;
        z1 = (INT32)wsptr[2];
        z2 = (INT32)wsptr[4];
        z3 = (INT32)wsptr[6];
        tmp3 = ((z3) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp1 = tmp0 + tmp3;
        tmp2 = tmp0 - tmp3 - tmp3;
        tmp0 = ((z1 - z2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 = tmp2 + tmp0;
        tmp14 = tmp2 - tmp0 - tmp0;
        tmp0 = ((z1 + z2) * (((INT32)((1.3289260490000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((INT32)((1.0833504410000001) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z2) * (((INT32)((0.245575608) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp1 + tmp0 - tmp3;
        tmp12 = tmp1 - tmp0 + tmp2;
        tmp13 = tmp1 - tmp2 + tmp3;
        z1 = (INT32)wsptr[1];
        z2 = (INT32)wsptr[3];
        z3 = (INT32)wsptr[5];
        z4 = (INT32)wsptr[7];
        z2 = ((z2) * (-((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1 + z3) * (((INT32)((0.90903895499999998) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((INT32)((0.48368952500000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp2 + tmp3 - z2;
        tmp1 = ((z3 - z4) * (((INT32)((1.392728481) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z2 - tmp1;
        tmp3 += z2 + tmp1;
        tmp1 = ((z1 - z3 - z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[8] = range_limit[(int)((tmp10 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[7] = range_limit[(int)((tmp11 - tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp12 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp12 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp13 + tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp13 - tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        wsptr += 8;
    }
}
}
