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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 3; ctr++) {
        {
            outptr = output_buf[ctr * 2] + output_col;
            tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
            tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
            tmp2 = (JLONG)wsptr[4];
            tmp10 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
            tmp1 = tmp0 + tmp10;
            tmp11 = tmp0 - tmp10 - tmp10;
            tmp10 = (JLONG)wsptr[2];
            tmp0 = ((tmp10) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
            tmp10 = tmp1 + tmp0;
            tmp12 = tmp1 - tmp0;
            z1 = (JLONG)wsptr[1];
            z2 = (JLONG)wsptr[3];
            z3 = (JLONG)wsptr[5];
            tmp1 = ((z1 + z3) * (((JLONG)((0.366025404) * (((JLONG)1) << 13) + 0.5))));
            tmp0 = tmp1 + ((JLONG)((unsigned long)(z1 + z2) << (13)));
            tmp2 = tmp1 + ((JLONG)((unsigned long)(z3 - z2) << (13)));
            tmp1 = ((JLONG)((unsigned long)(z1 - z2 - z3) << (13)));
            outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[5] = range_limit[(int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[4] = range_limit[(int)((tmp11 - tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[2] = range_limit[(int)((tmp12 + tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[3] = range_limit[(int)((tmp12 - tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            wsptr += 6;
        }
        {
            outptr = output_buf[ctr * 2 + 1] + output_col;
            tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
            tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
            tmp2 = (JLONG)wsptr[4];
            tmp10 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
            tmp1 = tmp0 + tmp10;
            tmp11 = tmp0 - tmp10 - tmp10;
            tmp10 = (JLONG)wsptr[2];
            tmp0 = ((tmp10) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
            tmp10 = tmp1 + tmp0;
            tmp12 = tmp1 - tmp0;
            z1 = (JLONG)wsptr[1];
            z2 = (JLONG)wsptr[3];
            z3 = (JLONG)wsptr[5];
            tmp1 = ((z1 + z3) * (((JLONG)((0.366025404) * (((JLONG)1) << 13) + 0.5))));
            tmp0 = tmp1 + ((JLONG)((unsigned long)(z1 + z2) << (13)));
            tmp2 = tmp1 + ((JLONG)((unsigned long)(z3 - z2) << (13)));
            tmp1 = ((JLONG)((unsigned long)(z1 - z2 - z3) << (13)));
            outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[5] = range_limit[(int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[4] = range_limit[(int)((tmp11 - tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[2] = range_limit[(int)((tmp12 + tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[3] = range_limit[(int)((tmp12 - tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            wsptr += 6;
        }
    }
}
