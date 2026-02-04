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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping
    // Instead of direct or strided access, use an index lookup table to simulate irregular memory access.
    // This models scenarios where access patterns are determined at runtime or from metadata.

    static const int index_map[14][7] = {
        {0,1,2,3,4,5,6}, {7,8,9,10,11,12,13}, {14,15,16,17,18,19,20},
        {21,22,23,24,25,26,27}, {28,29,30,31,32,33,34}, {35,36,37,38,39,40,41},
        {42,43,44,45,46,47,48}, {49,50,51,52,53,54,55}, {56,57,58,59,60,61,62},
        {63,64,65,66,67,68,69}, {70,71,72,73,74,75,76}, {77,78,79,80,81,82,83},
        {84,85,86,87,88,89,90}, {91,92,93,94,95,96,97}
    };

    for (ctr = 0; ctr < 14; ctr++) {
        outptr = output_buf[ctr] + output_col;
        const int *idx = index_map[ctr];  // Get indirection indices for this iteration

        tmp23 = (INT32)wsptr[idx[0]] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp23 <<= 13;
        z1 = (INT32)wsptr[idx[2]];
        z2 = (INT32)wsptr[idx[4]];
        z3 = (INT32)wsptr[idx[6]];
        tmp20 = ((z2 - z3) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 = ((z1 - z2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp22 + tmp23 - ((z2) * (((INT32)((1.841218003) * (((INT32)1) << 13) + 0.5))));
        tmp10 = z1 + z3;
        z2 -= tmp10;
        tmp10 = ((tmp10) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + tmp23;
        tmp20 += tmp10 - ((z3) * (((INT32)((0.077722535999999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 += tmp10 - ((z1) * (((INT32)((2.4706022490000001) * (((INT32)1) << 13) + 0.5))));
        tmp23 += ((z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));
        z1 = (INT32)wsptr[idx[1]];
        z2 = (INT32)wsptr[idx[3]];
        z3 = (INT32)wsptr[idx[5]];
        tmp11 = ((z1 + z2) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 - tmp12;
        tmp11 += tmp12;
        tmp12 = ((z2 + z3) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp12;
        z2 = ((z1 + z3) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp12 += z2 + ((z3) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }
}
