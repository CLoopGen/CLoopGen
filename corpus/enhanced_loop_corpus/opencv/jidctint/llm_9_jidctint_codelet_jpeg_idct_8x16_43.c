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



void loop() {
    for (ctr = 0; ctr < 32; ctr++) {
        outptr = output_buf[ctr % 16] + output_col;
        z2 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        z3 = (INT32)wsptr[4];
        tmp0 = (z2 + z3) << 13;
        tmp1 = (z2 - z3) << 13;
        z2 = (INT32)wsptr[2];
        z3 = (INT32)wsptr[6];
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp2 = z1 + ((z2) * (((INT32)6270)));
        tmp3 = z1 - ((z3) * (((INT32)15137)));
        tmp10 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        tmp11 = tmp1 + tmp3;
        tmp12 = tmp1 - tmp3;

        // Increased complexity: additional butterfly operations and intermediate combinations
        INT32 tmpA = (tmp10 + tmp11) >> 1;
        INT32 tmpB = (tmp12 + tmp13) >> 1;
        INT32 tmpC = (tmp10 - tmp11) >> 1;
        INT32 tmpD = (tmp12 - tmp13) >> 1;

        tmp0 = (INT32)wsptr[7];
        tmp1 = (INT32)wsptr[5];
        tmp2 = (INT32)wsptr[3];
        tmp3 = (INT32)wsptr[1];
        z2 = tmp0 + tmp2;
        z3 = tmp1 + tmp3;
        z1 = ((z2 + z3) * (((INT32)9633)));
        z2 = ((z2) * (-((INT32)16069))) + z1;
        z3 = ((z3) * (-((INT32)3196))) + z1;
        z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
        INT32 t0 = ((tmp0) * (((INT32)2446))) + z1 + z2;
        INT32 t3 = ((tmp3) * (((INT32)12299))) + z1 + z3;
        z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
        INT32 t1 = ((tmp1) * (((INT32)16819))) + z1 + z3;
        INT32 t2 = ((tmp2) * (((INT32)25172))) + z1 + z2;

        // Write multiple times per iteration with offset variations to increase memory traffic
        for (int offset = 0; offset < 2; offset++) {
            int shift = (13 + 2 + 3) + offset;
            int mask = ((128 << 2) * 2 - 1) >> offset;
            if (mask == 0) mask = 1;

            outptr[(0 + offset) % 8] = range_limit[(int)((tmpA + t3) >> shift) & mask];
            outptr[(7 - offset) % 8] = range_limit[(int)((tmpA - t3) >> shift) & mask];
            outptr[(1 + offset) % 8] = range_limit[(int)((tmpB + t2) >> shift) & mask];
            outptr[(6 - offset) % 8] = range_limit[(int)((tmpB - t2) >> shift) & mask];
            outptr[(2 + offset) % 8] = range_limit[(int)((tmpC + t1) >> shift) & mask];
            outptr[(5 - offset) % 8] = range_limit[(int)((tmpC - t1) >> shift) & mask];
            outptr[(3 + offset) % 8] = range_limit[(int)((tmpD + t0) >> shift) & mask];
            outptr[(4 - offset) % 8] = range_limit[(int)((tmpD - t0) >> shift) & mask];
        }

        wsptr += 8;
    }
}
