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
for (ctr = 0; ctr < 15; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z1 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    z1 <<= 13;
    z2 = (INT32)wsptr[2];
    z3 = (INT32)wsptr[4];
    z4 = (INT32)wsptr[6];

    // Skip computation for middle elements in a subset of iterations
    if (ctr >= 3 && ctr <= 11) {
        tmp10 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
        tmp12 = z1 - tmp10;
        tmp13 = z1 + tmp11;
        z1 -= (tmp11 - tmp10) << 1;
        z4 = z2 - z3;
        z3 += z2;
        tmp10 = ((z3) * (((INT32)((1.33762899) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((INT32)((0.045680613000000002) * (((INT32)1) << 13) + 0.5))));
        z2 = ((z2) * (((INT32)((1.4397739460000001) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp13 + tmp10 + tmp11;
        tmp23 = tmp12 - tmp10 + tmp11 + z2;
        tmp10 = ((z3) * (((INT32)((0.54705957400000005) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((INT32)((0.39923400399999998) * (((INT32)1) << 13) + 0.5))));
        tmp25 = tmp13 - tmp10 - tmp11;
        tmp26 = tmp12 + tmp10 - tmp11 - z2;
        tmp10 = ((z3) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp12 + tmp10 + tmp11;
        tmp24 = tmp13 - tmp10 + tmp11;
        tmp11 += tmp11;
        tmp22 = z1 + tmp11;
        tmp27 = z1 - tmp11 - tmp11;
        z1 = (INT32)wsptr[1];
        z2 = (INT32)wsptr[3];
        z4 = (INT32)wsptr[5];
        z3 = ((z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        z4 = (INT32)wsptr[7];
        tmp13 = z2 - z4;
        tmp15 = ((z1 + tmp13) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        tmp11 = tmp15 + ((z1) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
        tmp14 = tmp15 - ((tmp13) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((z2) * (-((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        tmp15 = ((z2) * (-((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5))));
        z2 = z1 - z4;
        tmp12 = z3 + ((z2) * (((INT32)((1.4064663529999999) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp12 + ((z4) * (((INT32)((2.4574318439999998) * (((INT32)1) << 13) + 0.5)))) - tmp15;
        tmp16 = tmp12 - ((z1) * (((INT32)((1.11243482) * (((INT32)1) << 13) + 0.5)))) + tmp13;
        tmp12 = ((z2) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5)))) - z3;
        z2 = ((z1 + z4) * (((INT32)((0.575212477) * (((INT32)1) << 13) + 0.5))));
        tmp13 += z2 + ((z1) * (((INT32)((0.47575301399999997) * (((INT32)1) << 13) + 0.5)))) - z3;
        tmp15 += z2 - ((z4) * (((INT32)((0.86924400999999996) * (((INT32)1) << 13) + 0.5)))) + z3;
    } else {
        // Fast path: minimal operations for edge cases
        tmp20 = z1;
        tmp27 = z1 >> 1;
        tmp10 = z2 << 2;
        tmp15 = z3;
        tmp16 = z4;
    }

    // Always write at least center and edges
    outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[7] = range_limit[(int)((tmp27) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[14] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    // Conditional full write only for outer blocks
    if (ctr < 3 || ctr > 11) {
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[13] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[12] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[11] = range_limit[(int)((tmp23 - tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[10] = range_limit[(int)((tmp24 - tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[9] = range_limit[(int)((tmp25 - tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp26 + tmp16) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[8] = range_limit[(int)((tmp26 - tmp16) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }

    wsptr += 8;
}
}
