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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 7; ctr++) {
        outptr = output_buf[ctr] + output_col;

        // Reorder independent computations to eliminate false dependencies and enable parallelism
        // Load all wsptr values first to minimize address dependency chains
        INT32 w0 = (INT32)wsptr[0];
        INT32 w1 = (INT32)wsptr[1];
        INT32 w2 = (INT32)wsptr[2];
        INT32 w3 = (INT32)wsptr[3];
        INT32 w4 = (INT32)wsptr[4];
        INT32 w5 = (INT32)wsptr[5];
        INT32 w6 = (INT32)wsptr[6];
        INT32 w7 = (INT32)wsptr[7];

        // Precompute constants outside recurring expressions to break redundant recalculations
        const INT32 shift_factor = 13 + 2 + 3;
        const INT32 mask = (128 << 2) * 2 - 1;
        const INT32 offset_base = ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2))) << 13;

        // Break loop-carried WAW hazard by using local temporaries instead of shared globals until end
        INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15, local_tmp16;
        INT32 local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25, local_tmp26;

        // Eliminate sequential dependency between z1/z4 reuse by renaming variables early
        INT32 t_z1 = w0 + offset_base;
        INT32 t_z4 = w4;
        INT32 t_z2 = t_z4 * (INT32)(1.274162392 * (1 << 13) + 0.5);
        INT32 t_z3 = t_z4 * (INT32)(0.31469212299999999 * (1 << 13) + 0.5);
        t_z4 = t_z4 * (INT32)(0.88174773399999995 * (1 << 13) + 0.5);

        local_tmp10 = t_z1 + t_z2;
        local_tmp11 = t_z1 + t_z3;
        local_tmp12 = t_z1 - t_z4;
        local_tmp23 = t_z1 - ((t_z2 + t_z3 - t_z4) << 1);

        t_z1 = w2;
        t_z2 = w6;
        t_z3 = (t_z1 + t_z2) * (INT32)(1.105676686 * (1 << 13) + 0.5);
        local_tmp13 = t_z3 + (t_z1 * (INT32)(0.27307958999999998 * (1 << 13) + 0.5));
        local_tmp14 = t_z3 - (t_z2 * (INT32)(1.719280954 * (1 << 13) + 0.5));
        local_tmp15 = (t_z1 * (INT32)(0.61360426800000001 * (1 << 13) + 0.5)) -
                      (t_z2 * (INT32)(1.3787562760000001 * (1 << 13) + 0.5));

        local_tmp20 = local_tmp10 + local_tmp13;
        local_tmp26 = local_tmp10 - local_tmp13;
        local_tmp21 = local_tmp11 + local_tmp14;
        local_tmp25 = local_tmp11 - local_tmp14;
        local_tmp22 = local_tmp12 + local_tmp15;
        local_tmp24 = local_tmp12 - local_tmp15;

        t_z1 = w1;
        t_z2 = w3;
        t_z3 = w5;
        t_z4 = w7 << 13;
        local_tmp14 = t_z1 + t_z3;
        local_tmp11 = (t_z1 + t_z2) * (INT32)(1.334852607 * (1 << 13) + 0.5);
        local_tmp12 = local_tmp14 * (INT32)(1.1974488459999999 * (1 << 13) + 0.5);
        local_tmp10 = local_tmp11 + local_tmp12 + t_z4 - (t_z1 * (INT32)(1.1269801690000001 * (1 << 13) + 0.5));
        local_tmp14 = local_tmp14 * (INT32)(0.752406978 * (1 << 13) + 0.5);
        local_tmp16 = local_tmp14 - (t_z1 * (INT32)(1.061150426 * (1 << 13) + 0.5));
        t_z1 -= t_z2;
        local_tmp15 = (t_z1 * (INT32)(0.46708512899999999 * (1 << 13) + 0.5)) - t_z4;
        local_tmp16 += local_tmp15;
        local_tmp13 = (t_z2 + t_z3) * (-(INT32)(0.15834168100000001 * (1 << 13) + 0.5)) - t_z4;
        local_tmp11 += local_tmp13 - (t_z2 * (INT32)(0.42410394800000001 * (1 << 13) + 0.5));
        local_tmp12 += local_tmp13 - (t_z3 * (INT32)(2.3739597730000002 * (1 << 13) + 0.5));
        local_tmp13 = (t_z3 - t_z2) * (INT32)(1.405321284 * (1 << 13) + 0.5);
        local_tmp14 += local_tmp13 + t_z4 - (t_z3 * (INT32)(1.6906431334000001 * (1 << 13) + 0.5));
        local_tmp15 += local_tmp13 + (t_z2 * (INT32)(0.67495756699999998 * (1 << 13) + 0.5));
        local_tmp13 = ((t_z1 - t_z3) << 13) + t_z4;

        // Final write-back with no intermediate side effects — all computation is isolated
        outptr[0]  = range_limit[(int)((local_tmp20 + local_tmp10) >> shift_factor) & mask];
        outptr[13] = range_limit[(int)((local_tmp20 - local_tmp10) >> shift_factor) & mask];
        outptr[1]  = range_limit[(int)((local_tmp21 + local_tmp11) >> shift_factor) & mask];
        outptr[12] = range_limit[(int)((local_tmp21 - local_tmp11) >> shift_factor) & mask];
        outptr[2]  = range_limit[(int)((local_tmp22 + local_tmp12) >> shift_factor) & mask];
        outptr[11] = range_limit[(int)((local_tmp22 - local_tmp12) >> shift_factor) & mask];
        outptr[3]  = range_limit[(int)((local_tmp23 + local_tmp13) >> shift_factor) & mask];
        outptr[10] = range_limit[(int)((local_tmp23 - local_tmp13) >> shift_factor) & mask];
        outptr[4]  = range_limit[(int)((local_tmp24 + local_tmp14) >> shift_factor) & mask];
        outptr[9]  = range_limit[(int)((local_tmp24 - local_tmp14) >> shift_factor) & mask];
        outptr[5]  = range_limit[(int)((local_tmp25 + local_tmp15) >> shift_factor) & mask];
        outptr[8]  = range_limit[(int)((local_tmp25 - local_tmp15) >> shift_factor) & mask];
        outptr[6]  = range_limit[(int)((local_tmp26 + local_tmp16) >> shift_factor) & mask];
        outptr[7]  = range_limit[(int)((local_tmp26 - local_tmp16) >> shift_factor) & mask];

        wsptr += 8;
    }
}
