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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 16; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Combine initial computations into fewer expressions to reduce intermediate dependencies
    INT32 w0 = (INT32)wsptr[0];
    INT32 w4 = (INT32)wsptr[4];
    INT32 base = w0 + w4;
    INT32 diff = w0 - w4;
    INT32 w2 = (INT32)wsptr[2];
    INT32 w6 = (INT32)wsptr[6];
    INT32 sum_even = w2 + w6;
    INT32 z1 = sum_even * 4433;
    INT32 tmp2_val = z1 + (w2 * 6270);
    INT32 tmp3_val = z1 - (w6 * 15137);

    // Fold constants and eliminate redundant temporaries early
    INT32 offset = ((((INT32)(128 << 2)) << 5) + (1 << 4));
    INT32 tmp0_val = ((base + offset) << 13);
    INT32 tmp1_val = (diff << 13);
    INT32 tmp10_val = tmp0_val + tmp2_val;
    INT32 tmp13_val = tmp0_val - tmp2_val;
    INT32 tmp11_val = tmp1_val + tmp3_val;
    INT32 tmp12_val = tmp1_val - tmp3_val;

    // Introduce artificial anti-dependence by reusing tmp0, tmp1, etc., in a different order
    INT32 w7 = (INT32)wsptr[7];
    INT32 w5 = (INT32)wsptr[5];
    INT32 w3 = (INT32)wsptr[3];
    INT32 w1 = (INT32)wsptr[1];

    INT32 psum = w7 + w3;
    INT32 qsum = w5 + w1;
    INT32 rsum = w7 + w1;
    INT32 ssum = w5 + w3;

    INT32 y1 = (psum + qsum) * 9633;
    INT32 part_z2 = y1 - (psum * 16069);
    INT32 part_z3 = y1 - (qsum * 3196);

    INT32 y2 = rsum * 7373;
    INT32 y3 = ssum * 20995;

    INT32 final_0 = (w7 * 2446) - y2 + part_z2;
    INT32 final_3 = (w1 * 12299) - y2 + part_z3;
    INT32 final_1 = (w5 * 16819) - y3 + part_z3;
    INT32 final_2 = (w3 * 25172) - y3 + part_z2;

    // Maintain same memory access pattern but use computed values directly
    int shift = 18;
    int mask = 1023;
    outptr[0] = range_limit[(int)((tmp10_val + final_3) >> shift) & mask];
    outptr[7] = range_limit[(int)((tmp10_val - final_3) >> shift) & mask];
    outptr[1] = range_limit[(int)((tmp11_val + final_2) >> shift) & mask];
    outptr[6] = range_limit[(int)((tmp11_val - final_2) >> shift) & mask];
    outptr[2] = range_limit[(int)((tmp12_val + final_1) >> shift) & mask];
    outptr[5] = range_limit[(int)((tmp12_val - final_1) >> shift) & mask];
    outptr[3] = range_limit[(int)((tmp13_val + final_0) >> shift) & mask];
    outptr[4] = range_limit[(int)((tmp13_val - final_0) >> shift) & mask];

    wsptr += 8;
}
}
