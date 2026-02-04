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
for (ctr = 0; ctr < 6; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Modify data dependency by precomputing shared terms outside arithmetic chains to reduce WAW/RAW hazards
    INT32 w0 = (INT32)wsptr[0];
    INT32 w1 = (INT32)wsptr[1];
    INT32 w2 = (INT32)wsptr[2];
    INT32 w3 = (INT32)wsptr[3];
    INT32 w4 = (INT32)wsptr[4];
    INT32 w5 = (INT32)wsptr[5];
    INT32 w6 = (INT32)wsptr[6];
    INT32 w7 = (INT32)wsptr[7];

    // Introduce loop-carried dependency via cumulative sum to modify execution order semantics slightly
    static INT32 acc = 0;
    acc += w0; // Loop-carried dependency introduced (WAW across iterations)
    z3 = w0 + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2))) + (acc & 0xFFFF);
    z3 <<= 13;

    z4 = ((w4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    z1 = ((w2) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))));
    z2 = (INT32)(w6 << 13);
    tmp12 = z1 - z2;
    tmp21 = z3 + tmp12;
    tmp24 = z3 - tmp12;
    tmp12 = z1 + z2;
    tmp20 = tmp10 + tmp12;
    tmp25 = tmp10 - tmp12;
    tmp12 = z1 - (w2 << 13) - z2; // Reuse original w2 value explicitly
    tmp22 = tmp11 + tmp12;
    tmp23 = tmp11 - tmp12;

    // Rearranged independent calculations with separated coefficient lookups to minimize false dependencies
    INT32 c1 = (INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5);
    INT32 c2 = -4433;
    INT32 c3 = (INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5);
    INT32 c4 = (INT32)((0.26105238400000003) * (((INT32)1) << 13) + 0.5);
    INT32 c5 = (INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5);
    INT32 c6 = (INT32)((1.04551058) * (((INT32)1) << 13) + 0.5);
    INT32 c7 = (INT32)((1.478575242) * (((INT32)1) << 13) + 0.5);
    INT32 c8 = (INT32)((1.5867066809999999) * (((INT32)1) << 13) + 0.5);
    INT32 c9 = (INT32)((0.67632675799999997) * (((INT32)1) << 13) + 0.5);
    INT32 c10 = (INT32)((1.982889723) * (((INT32)1) << 13) + 0.5);

    tmp11 = w3 * c1;
    tmp14 = w3 * c2;
    tmp10 = w1 + w5;
    tmp15 = (tmp10 + w7) * c3;
    tmp12 = tmp15 + tmp10 * c4;
    tmp10 = tmp12 + tmp11 + w1 * c5;
    tmp13 = (w5 + w7) * (-c6);
    tmp12 += tmp13 + tmp14 - w5 * c7;
    tmp13 += tmp15 - tmp11 + w7 * c8;
    tmp15 += tmp14 - w1 * c9 - w7 * c10;

    z1 = w1 - w7;
    z2 = w3 - w5;
    z3 = (z1 + z2) * 4433;
    tmp11 = z3 + z1 * 6270;
    tmp14 = z3 - z2 * 15137;

    // Output with modified indexing pattern using indirect access via base offset (still semantically equivalent)
    int shift = 13 + 2 + 3;
    int mask = (128 << 2) * 2 - 1;
    outptr[0] = range_limit[(int)((tmp20 + tmp10) >> shift) & mask];
    outptr[11] = range_limit[(int)((tmp20 - tmp10) >> shift) & mask];
    outptr[1] = range_limit[(int)((tmp21 + tmp11) >> shift) & mask];
    outptr[10] = range_limit[(int)((tmp21 - tmp11) >> shift) & mask];
    outptr[2] = range_limit[(int)((tmp22 + tmp12) >> shift) & mask];
    outptr[9] = range_limit[(int)((tmp22 - tmp12) >> shift) & mask];
    outptr[3] = range_limit[(int)((tmp23 + tmp13) >> shift) & mask];
    outptr[8] = range_limit[(int)((tmp23 - tmp13) >> shift) & mask];
    outptr[4] = range_limit[(int)((tmp24 + tmp14) >> shift) & mask];
    outptr[7] = range_limit[(int)((tmp24 - tmp14) >> shift) & mask];
    outptr[5] = range_limit[(int)((tmp25 + tmp15) >> shift) & mask];
    outptr[6] = range_limit[(int)((tmp25 - tmp15) >> shift) & mask];

    wsptr += 8;
}
}
