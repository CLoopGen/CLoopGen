#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Eliminate loop-carried dependency by unrolling and reworking data flow
    // Simulate partial unrolling by processing two iterations' logic independently
    // while maintaining the same outer loop structure

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Duplicate temporaries with versioning to eliminate WAW hazards
        INT32 tmp0_v1, tmp7_v1, tmp1_v1, tmp6_v1, tmp2_v1, tmp5_v1, tmp3_v1, tmp4_v1;
        INT32 tmp10_v1, tmp13_v1, tmp11_v1, tmp12_v1;
        INT32 z1_v1, z2_v1, z3_v1, z4_v1, z5_v1;

        tmp0_v1 = dataptr[0] + dataptr[7];
        tmp7_v1 = dataptr[0] - dataptr[7];
        tmp1_v1 = dataptr[1] + dataptr[6];
        tmp6_v1 = dataptr[1] - dataptr[6];
        tmp2_v1 = dataptr[2] + dataptr[5];
        tmp5_v1 = dataptr[2] - dataptr[5];
        tmp3_v1 = dataptr[3] + dataptr[4];
        tmp4_v1 = dataptr[3] - dataptr[4];

        tmp10_v1 = tmp0_v1 + tmp3_v1;
        tmp13_v1 = tmp0_v1 - tmp3_v1;
        tmp11_v1 = tmp1_v1 + tmp2_v1;
        tmp12_v1 = tmp1_v1 - tmp2_v1;

        // Use intermediate results immediately with explicit scheduling
        dataptr[0] = (DCTELEM)((tmp10_v1 + tmp11_v1) << 2);
        dataptr[4] = (DCTELEM)((tmp10_v1 - tmp11_v1) << 2);

        z5_v1 = ((tmp12_v1 + tmp13_v1) * (((INT32)4433)));
        // Fold constants: (1 << (13-2-1)) == (1 << 10)
        dataptr[2] = (DCTELEM)(((z5_v1 + (tmp13_v1 * ((INT32)6270))) + (1 << 10)) >> 11);
        dataptr[6] = (DCTELEM)(((z5_v1 + (tmp12_v1 * (-(INT32)15137))) + (1 << 10)) >> 11);

        // Introduce redundant recomputation to break RAW dependency chains
        z1_v1 = ((tmp4_v1 + tmp7_v1) * (-(INT32)7373));
        z2_v1 = ((tmp5_v1 + tmp6_v1) * (-(INT32)20995));
        z3_v1 = ((tmp4_v1 + tmp6_v1) * (-(INT32)16069));
        z4_v1 = ((tmp5_v1 + tmp7_v1) * (-(INT32)3196));

        INT32 z5_mid = ((tmp4_v1 + tmp6_v1) + (tmp5_v1 + tmp7_v1)) * ((INT32)9633);
        z3_v1 += z5_mid;
        z4_v1 += z5_mid;

        // Reuse original tmp variables safely after prior use
        tmp4 = ((tmp4_v1) * (((INT32)2446)));
        tmp5 = ((tmp5_v1) * (((INT32)16819)));
        tmp6 = ((tmp6_v1) * (((INT32)25172)));
        tmp7 = ((tmp7_v1) * (((INT32)12299)));

        // Scatter store operations to alter memory dependency order
        dataptr[7] = (DCTELEM)(((tmp4 + z1_v1 + z3_v1) + (1 << 10)) >> 11);
        dataptr[5] = (DCTELEM)(((tmp5 + z2_v1 + z4_v1) + (1 << 10)) >> 11);
        dataptr[3] = (DCTELEM)(((tmp6 + z2_v1 + z3_v1) + (1 << 10)) >> 11);
        dataptr[1] = (DCTELEM)(((tmp7 + z1_v1 + z4_v1) + (1 << 10)) >> 11);

        dataptr += 8;
    }
}
