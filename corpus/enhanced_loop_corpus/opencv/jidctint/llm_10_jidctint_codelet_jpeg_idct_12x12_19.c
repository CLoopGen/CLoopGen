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
for (ctr = 0; ctr < 24; ctr += 2) {
    outptr = output_buf[ctr % 12] + output_col;
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

    // Second iteration of original body adapted for next index
    if (ctr + 1 < 24) {
        JSAMPROW outptr2 = output_buf[(ctr + 1) % 12] + output_col;
        INT32 tmp10b, tmp11b, tmp12b, tmp13b, tmp14b, tmp15b;
        INT32 tmp20b, tmp21b, tmp22b, tmp23b, tmp24b, tmp25b;
        INT32 z1b, z2b, z3b, z4b;

        z3b = (INT32)wsptr[8] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        z3b <<= 13;
        z4b = (INT32)wsptr[12];
        z4b = ((z4b) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp10b = z3b + z4b;
        tmp11b = z3b - z4b;
        z1b = (INT32)wsptr[10];
        z4b = ((z1b) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))));
        z1b <<= 13;
        z2b = (INT32)wsptr[14];
        z2b <<= 13;
        tmp12b = z1b - z2b;
        tmp21b = z3b + tmp12b;
        tmp24b = z3b - tmp12b;
        tmp12b = z4b + z2b;
        tmp20b = tmp10b + tmp12b;
        tmp25b = tmp10b - tmp12b;
        tmp12b = z4b - z1b - z2b;
        tmp22b = tmp11b + tmp12b;
        tmp23b = tmp11b - tmp12b;

        z1b = (INT32)wsptr[9];
        z2b = (INT32)wsptr[11];
        z3b = (INT32)wsptr[13];
        z4b = (INT32)wsptr[15];
        tmp11b = ((z2b) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp14b = ((z2b) * (-((INT32)4433)));
        tmp10b = z1b + z3b;
        tmp15b = ((tmp10b + z4b) * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));
        tmp12b = tmp15b + ((tmp10b) * (((INT32)((0.26105238400000003) * (((INT32)1) << 13) + 0.5))));
        tmp10b = tmp12b + tmp11b + ((z1b) * (((INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5))));
        tmp13b = ((z3b + z4b) * (-((INT32)((1.04551058) * (((INT32)1) << 13) + 0.5))));
        tmp12b += tmp13b + tmp14b - ((z3b) * (((INT32)((1.478575242) * (((INT32)1) << 13) + 0.5))));
        tmp13b += tmp15b - tmp11b + ((z4b) * (((INT32)((1.5867066809999999) * (((INT32)1) << 13) + 0.5))));
        tmp15b += tmp14b - ((z1b) * (((INT32)((0.67632675799999997) * (((INT32)1) << 13) + 0.5)))) - ((z4b) * (((INT32)((1.982889723) * (((INT32)1) << 13) + 0.5))));
        z1b -= z4b;
        z2b -= z3b;
        z3b = ((z1b + z2b) * (((INT32)4433)));
        tmp11b = z3b + ((z1b) * (((INT32)6270)));
        tmp14b = z3b - ((z2b) * (((INT32)15137)));

        outptr2[0] = range_limit[(int)((tmp20b + tmp10b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[11] = range_limit[(int)((tmp20b - tmp10b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[1] = range_limit[(int)((tmp21b + tmp11b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[10] = range_limit[(int)((tmp21b - tmp11b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[2] = range_limit[(int)((tmp22b + tmp12b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[9] = range_limit[(int)((tmp22b - tmp12b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[3] = range_limit[(int)((tmp23b + tmp13b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[8] = range_limit[(int)((tmp23b - tmp13b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[4] = range_limit[(int)((tmp24b + tmp14b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[7] = range_limit[(int)((tmp24b - tmp14b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[5] = range_limit[(int)((tmp25b + tmp15b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr2[6] = range_limit[(int)((tmp25b - tmp15b) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }

    wsptr += 16;
}
}
