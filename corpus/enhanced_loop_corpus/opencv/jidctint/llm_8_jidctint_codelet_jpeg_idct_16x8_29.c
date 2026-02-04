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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
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
for (ctr = 0; ctr < 8; ctr += 2) {
    outptr = output_buf[ctr] + output_col;
    tmp0 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    tmp0 <<= 13;
    z1 = (INT32)wsptr[4];
    tmp1 = ((z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((z1) * (((INT32)4433)));
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp12 = tmp0 + tmp2;
    tmp13 = tmp0 - tmp2;
    z1 = (INT32)wsptr[2];
    z2 = (INT32)wsptr[6];
    z3 = z1 - z2;
    z4 = ((z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
    z3 = ((z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
    tmp0 = z3 + ((z2) * (((INT32)20995)));
    tmp1 = z4 + ((z1) * (((INT32)7373)));
    tmp2 = z3 - ((z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
    tmp3 = z4 - ((z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp0;
    tmp27 = tmp10 - tmp0;
    tmp21 = tmp12 + tmp1;
    tmp26 = tmp12 - tmp1;
    tmp22 = tmp13 + tmp2;
    tmp25 = tmp13 - tmp2;
    tmp23 = tmp11 + tmp3;
    tmp24 = tmp11 - tmp3;

    outptr[0] = range_limit[(int)((tmp20 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[15] = range_limit[(int)((tmp20 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21 + tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[14] = range_limit[(int)((tmp21 - tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp22 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[13] = range_limit[(int)((tmp22 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp23 + tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[12] = range_limit[(int)((tmp23 - tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    if (ctr + 1 < 8) {
        outptr = output_buf[ctr+1] + output_col;
        tmp0 = (INT32)wsptr[8] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp0 <<= 13;
        z1 = (INT32)wsptr[12];
        tmp1 = ((z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((INT32)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        z1 = (INT32)wsptr[10];
        z2 = (INT32)wsptr[14];
        z3 = z1 - z2;
        z4 = ((z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
        z3 = ((z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = z3 + ((z2) * (((INT32)20995)));
        tmp1 = z4 + ((z1) * (((INT32)7373)));
        tmp2 = z3 - ((z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
        tmp3 = z4 - ((z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp0;
        tmp27 = tmp10 - tmp0;
        tmp21 = tmp12 + tmp1;
        tmp26 = tmp12 - tmp1;
        tmp22 = tmp13 + tmp2;
        tmp25 = tmp13 - tmp2;
        tmp23 = tmp11 + tmp3;
        tmp24 = tmp11 - tmp3;

        outptr[0] = range_limit[(int)((tmp20 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[15] = range_limit[(int)((tmp20 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[14] = range_limit[(int)((tmp21 - tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[13] = range_limit[(int)((tmp22 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23 + tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[12] = range_limit[(int)((tmp23 - tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }

    wsptr += 16;
}
}
