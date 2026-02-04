#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Eliminate some intermediate variables to remove unnecessary dependencies
    // Flatten expressions to reduce temporary storage (reducing WAW and WAR hazards)

    DCTELEM t0_plus_7 = dataptr[8 * 0] + dataptr[8 * 7];
    DCTELEM t0_minus_7 = dataptr[8 * 0] - dataptr[8 * 7];
    DCTELEM t1_plus_6 = dataptr[8 * 1] + dataptr[8 * 6];
    DCTELEM t1_minus_6 = dataptr[8 * 1] - dataptr[8 * 6];
    DCTELEM t2_plus_5 = dataptr[8 * 2] + dataptr[8 * 5];
    DCTELEM t2_minus_5 = dataptr[8 * 2] - dataptr[8 * 5];
    DCTELEM t3_plus_4 = dataptr[8 * 3] + dataptr[8 * 4];
    DCTELEM t3_minus_4 = dataptr[8 * 3] - dataptr[8 * 4];

    // Compute results directly without storing intermediates like tmp10, tmp11, etc.
    dataptr[8 * 0] = (t0_plus_7 + t3_plus_4) + (t1_plus_6 + t2_plus_5);
    dataptr[8 * 4] = (t0_plus_7 + t3_plus_4) - (t1_plus_6 + t2_plus_5);

    z1 = ((DCTELEM)((((t1_plus_6 - t2_plus_5) + (t0_plus_7 - t3_plus_4)) * (((JLONG)181))) >> (8)));
    dataptr[8 * 2] = (t0_plus_7 - t3_plus_4) + z1;
    dataptr[8 * 6] = (t0_plus_7 - t3_plus_4) - z1;

    // Reuse expression values immediately to minimize live ranges and eliminate WAR/WAW
    DCTELEM t4_plus_5 = t3_minus_4 + t2_minus_5;
    DCTELEM t5_plus_6 = t2_minus_5 + t1_minus_6;
    DCTELEM t6_plus_7 = t1_minus_6 + t0_minus_7;

    z5 = ((DCTELEM)(((t4_plus_5 - t6_plus_7) * (((JLONG)98))) >> (8)));
    z2 = ((DCTELEM)(((t4_plus_5) * (((JLONG)139))) >> (8))) + z5;
    z4 = ((DCTELEM)(((t6_plus_7) * (((JLONG)334))) >> (8))) + z5;
    z3 = ((DCTELEM)(((t5_plus_6) * (((JLONG)181))) >> (8)));

    dataptr[8 * 5] = (t0_minus_7 - z3) + z2;
    dataptr[8 * 3] = (t0_minus_7 - z3) - z2;
    dataptr[8 * 1] = (t0_minus_7 + z3) + z4;
    dataptr[8 * 7] = (t0_minus_7 + z3) - z4;

    dataptr++;
}
}
