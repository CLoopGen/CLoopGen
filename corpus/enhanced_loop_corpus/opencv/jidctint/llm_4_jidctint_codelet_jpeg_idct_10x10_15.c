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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
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
for (ctr = 0; ctr < 10; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z3 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    z3 <<= 13;
    z4 = (INT32)wsptr[4];
    z1 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    z2 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z3 + z1;
    tmp11 = z3 - z2;
    tmp22 = z3 - ((z1 - z2) << 1);
    z2 = (INT32)wsptr[2];
    z3 = (INT32)wsptr[6];
    z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp12 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp12;
    tmp24 = tmp10 - tmp12;
    tmp21 = tmp11 + tmp13;
    tmp23 = tmp11 - tmp13;
    z1 = (INT32)wsptr[1];
    z2 = (INT32)wsptr[3];
    z3 = (INT32)wsptr[5];
    z3 <<= 13;
    z4 = (INT32)wsptr[7];
    tmp11 = z2 + z4;
    tmp13 = z2 - z4;
    tmp12 = ((tmp13) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5))));
    z4 = z3 + tmp12;
    tmp10 = ((z1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + z2 + z4;
    tmp14 = ((z1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;
    z2 = ((tmp11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    z4 = z3 - tmp12 - (tmp13 << (13 - 1));
    tmp12 = ((z1 - tmp13) << 13) - z3;
    tmp11 = ((z1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) - z2 - z4;
    tmp13 = ((z1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;

    if ((ctr & 1) == 0) {
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[9] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[8] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[7] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp23 - tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp24 - tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    } else {
        outptr[0] = range_limit[(int)((tmp20 + tmp10 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[9] = range_limit[(int)((tmp20 - tmp10 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[8] = range_limit[(int)((tmp21 - tmp11 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[7] = range_limit[(int)((tmp22 - tmp12 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp23 - tmp13 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp24 - tmp14 + 1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }
    wsptr += 8;
}
}
