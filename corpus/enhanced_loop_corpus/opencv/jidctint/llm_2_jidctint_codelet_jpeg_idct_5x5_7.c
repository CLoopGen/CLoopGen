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
for (ctr = 0; ctr < 5; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp12 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp12 = ((JLONG)((unsigned long)(tmp12) << (13)));
    tmp0 = (JLONG)wsptr[2];
    tmp1 = (JLONG)wsptr[4];
    z1 = ((tmp0 + tmp1) * (((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp1) * (((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5))));
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;
    tmp12 -= ((JLONG)((unsigned long)(z2) << (2)));
    z2 = (JLONG)wsptr[1];
    z3 = (JLONG)wsptr[3];
    z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
    // Change memory access to consecutive indexing using pointer arithmetic
    JSAMPLE* dst = outptr;
    dst[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    dst[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    dst[2] = range_limit[(int)((tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    dst[3] = range_limit[(int)((tmp11 - tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    dst[4] = range_limit[(int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    wsptr += 5;
}
}
