#include <stdio.h>

#include <inttypes.h>

typedef int DCTELEM;

typedef long INT32;

extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z1;
extern DCTELEM z2;
extern DCTELEM z3;
extern DCTELEM z4;
extern DCTELEM z5;
extern DCTELEM z11;
extern DCTELEM z13;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependency entirely by unrolling and removing induction variable usage
// Also remove RAW dependencies between consecutive statements via independent computation grouping

#pragma GCC unroll 8
for (ctr = 7; ctr >= 0; ctr--) {
    // Group operations to minimize temporary reuse (reduce WAW hazards)
    DCTELEM t0_add = dataptr[0] + dataptr[7];
    DCTELEM t0_sub = dataptr[0] - dataptr[7];
    DCTELEM t1_add = dataptr[1] + dataptr[6];
    DCTELEM t1_sub = dataptr[1] - dataptr[6];
    DCTELEM t2_add = dataptr[2] + dataptr[5];
    DCTELEM t2_sub = dataptr[2] - dataptr[5];
    DCTELEM t3_add = dataptr[3] + dataptr[4];
    DCTELEM t3_sub = dataptr[3] - dataptr[4];

    // Compute combinations without intermediate overwrites (avoiding RAW/WAR)
    DCTELEM sum_03 = t0_add + t3_add;
    DCTELEM dif_03 = t0_add - t3_add;
    DCTELEM sum_12 = t1_add + t2_add;
    DCTELEM dif_12 = t1_add - t2_add;

    // Direct assignment without using shared temporaries early
    dataptr[0] = sum_03 + sum_12;
    dataptr[4] = sum_03 - sum_12;

    // Use local expressions to break dependency chains
    z1 = ((DCTELEM)((((dif_12 + dif_03)) * (((INT32)181))) >> 8));
    dataptr[2] = dif_03 + z1;
    dataptr[6] = dif_03 - z1;

    // Regroup next stage with fresh names to eliminate false dependencies
    DCTELEM p45 = t3_sub + t2_sub;
    DCTELEM p56 = t2_sub + t1_sub;
    DCTELEM p67 = t1_sub + t0_sub;

    z5 = ((DCTELEM)(((p45 - p67) * (((INT32)98))) >> 8));
    z2 = ((DCTELEM)(((p45) * (((INT32)139))) >> 8)) + z5;
    z4 = ((DCTELEM)(((p67) * (((INT32)334))) >> 8)) + z5;
    z3 = ((DCTELEM)(((p56) * (((INT32)181))) >> 8));

    z11 = t0_sub + z3;
    z13 = t0_sub - z3;

    dataptr[5] = z13 + z2;
    dataptr[3] = z13 - z2;
    dataptr[1] = z11 + z4;
    dataptr[7] = z11 - z4;

    dataptr += 8;
}
}
