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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
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
for (ctr = 0; ctr < 12; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z3 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    z3 <<= 13;
    z4 = (INT32)wsptr[4];
    z4 = ((z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;
    z1 = (INT32)wsptr[2];
    z4 = ((z1) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))));
    z1 <<= 13;
    z2 = (INT32)wsptr[6];
    z2 <<= 13;
    tmp12 = z1 - z2;
    tmp21 = z3 + tmp12;
    tmp24 = z3 - tmp12;
    tmp12 = z4 + z2;
    tmp20 = tmp10 + tmp12;
    tmp25 = tmp10 - tmp12;
    tmp12 = z4 - z1 - z2;
    tmp22 = tmp11 + tmp12;
    tmp23 = tmp11 - tmp12;

    // Conditional skip of certain computation paths based on index
    if (ctr >= 6) {
        z1 = (INT32)wsptr[1];
        z2 = (INT32)wsptr[3];
        z3 = (INT32)wsptr[5];
        z4 = (INT32)wsptr[7];
        tmp11 = ((z2) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((z2) * (-((INT32)4433)));
        tmp10 = z1 + z3;
        tmp15 = ((tmp10 + z4) * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));
        tmp12 = tmp15 + ((tmp10) * (((INT32)((0.26105238400000003) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp12 + tmp11 + ((z1) * (((INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((z3 + z4) * (-((INT32)((1.04551058) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp13 + tmp14 - ((z3) * (((INT32)((1.478575242) * (((INT32)1) << 13) + 0.5))));
        tmp13 += tmp15 - tmp11 + ((z4) * (((INT32)((1.5867066809999999) * (((INT32)1) << 13) + 0.5))));
        tmp15 += tmp14 - ((z1) * (((INT32)((0.67632675799999997) * (((INT32)1) << 13) + 0.5)))) - ((z4) * (((INT32)((1.982889723) * (((INT32)1) << 13) + 0.5))));
    } else {
        // Use simplified approximation for first half
        tmp10 = (INT32)(wsptr[1] + wsptr[3] + wsptr[5] + wsptr[7]);
        tmp11 = tmp10 >> 1;
        tmp12 = tmp10 + tmp11;
        tmp13 = tmp10 - tmp11;
        tmp14 = tmp11;
        tmp15 = tmp10;
    }

    z1 = (INT32)wsptr[1]; // Re-read here to maintain dependency safety
    z2 = (INT32)wsptr[3];
    z3 = (INT32)wsptr[5];
    z4 = (INT32)wsptr[7];
    z1 -= z4;
    z2 -= z3;
    z3 = ((z1 + z2) * (((INT32)4433)));
    tmp11 = z3 + ((z1) * (((INT32)6270)));
    tmp14 = z3 - ((z2) * (((INT32)15137)));
    outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[11] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[10] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[9] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[8] = range_limit[(int)((tmp23 - tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[7] = range_limit[(int)((tmp24 - tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[6] = range_limit[(int)((tmp25 - tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    wsptr += 8;
}
}
