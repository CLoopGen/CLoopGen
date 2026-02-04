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
for (ctr = 0; ctr < 16; ctr++) {
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
    z1 = (INT32)wsptr[1];
    z2 = (INT32)wsptr[3];
    z3 = (INT32)wsptr[5];
    z4 = (INT32)wsptr[7];
    tmp11 = z1 + z3;
    tmp1 = ((z1 + z2) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp11) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    tmp3 = ((z1 + z4) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5))));
    tmp10 = ((z1 - z4) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((tmp11) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    tmp12 = ((z1 - z2) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 + tmp2 + tmp3 - ((z1) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5))));
    tmp13 = tmp10 + tmp11 + tmp12 - ((z1) * (((INT32)((1.835730603) * (((INT32)1) << 13) + 0.5))));
    z1 = ((z2 + z3) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5))));
    tmp1 += z1 + ((z2) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5))));
    tmp2 += z1 - ((z3) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5))));
    z1 = ((z3 - z2) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
    tmp11 += z1 - ((z3) * (((INT32)((0.76636728200000004) * (((INT32)1) << 13) + 0.5))));
    tmp12 += z1 + ((z2) * (((INT32)((1.971951411) * (((INT32)1) << 13) + 0.5))));
    z2 += z4;
    z1 = ((z2) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    tmp1 += z1;
    tmp3 += z1 + ((z4) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5))));
    z2 = ((z2) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    tmp10 += z2 + ((z4) * (((INT32)((3.141271809) * (((INT32)1) << 13) + 0.5))));
    tmp12 += z2;
    z2 = ((z3 + z4) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
    tmp2 += z2;
    tmp3 += z2;
    z2 = ((z4 - z3) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    tmp10 += z2;
    tmp11 += z2;
    outptr[0] = range_limit[(int)((tmp20 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[15] = range_limit[(int)((tmp20 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21 + tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[14] = range_limit[(int)((tmp21 - tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp22 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[13] = range_limit[(int)((tmp22 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp23 + tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[12] = range_limit[(int)((tmp23 - tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp24 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[11] = range_limit[(int)((tmp24 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp25 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[10] = range_limit[(int)((tmp25 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[6] = range_limit[(int)((tmp26 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[9] = range_limit[(int)((tmp26 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[7] = range_limit[(int)((tmp27 + tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[8] = range_limit[(int)((tmp27 - tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    wsptr += 8;
}

}
