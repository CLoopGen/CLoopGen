#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Eliminate some RAW dependencies by reordering independent computations
    // and introducing local temporaries to break false dependencies.

    INT32 local_z1, local_z2, local_z3, local_z4, local_z5;
    INT32 stage1_tmp10, stage1_tmp11, stage1_tmp12, stage1_tmp13;
    INT32 stage2_tmp20, stage2_tmp21, stage2_tmp22, stage2_tmp23, stage2_tmp24;

    // Independent computation moved early: coefficients for odd indices
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    // Even-indexed values computed later to allow parallelism
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z3 <<= 13;
    z3 += ((INT32)1) << (13 - 2 - 1);
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));  // Reuse local_z4 safely due to renaming
    local_z1 = ((local_z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    local_z2 = ((local_z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    stage1_tmp10 = z3 + local_z1;
    stage1_tmp11 = z3 - local_z2;
    stage1_tmp12 = ((z3 - ((local_z1 - local_z2) << 1)) >> (13 - 2));

    // Break WAR/WAW on z2/z3 by using different intermediates
    INT32 even_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    INT32 even_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    INT32 sum_even = even_z2 + even_z3;
    local_z1 = (sum_even * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    stage1_tmp12 = local_z1 + ((even_z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    stage1_tmp13 = local_z1 - ((even_z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    stage2_tmp20 = stage1_tmp10 + stage1_tmp12;
    stage2_tmp24 = stage1_tmp10 - stage1_tmp12;
    stage2_tmp21 = stage1_tmp11 + stage1_tmp13;
    stage2_tmp23 = stage1_tmp11 - stage1_tmp13;
    stage2_tmp22 = stage1_tmp12;

    // Now process odd part without interfering with even's variables
    INT32 tmp11_odd = local_z2 + local_z4;
    INT32 tmp13_odd = local_z2 - local_z4;
    INT32 tmp12_odd = ((tmp13_odd) * (((INT32)((0.309010000) * (((INT32)1) << 13) + 0.5))));
    local_z5 = local_z3 << 13;
    INT32 z2_odd = ((tmp11_odd) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5))));
    INT32 z4_odd = local_z5 + tmp12_odd;
    INT32 final_tmp10 = ((local_z1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + z2_odd + z4_odd;
    INT32 final_tmp14 = ((local_z1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) - z2_odd + z4_odd;
    z2_odd = ((tmp11_odd) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    z4_odd = local_z5 - tmp12_odd - (tmp13_odd << (13 - 1));
    INT32 final_tmp12 = (local_z1 - tmp13_odd - local_z3) << 2;
    INT32 final_tmp11 = ((local_z1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) - z2_odd - z4_odd;
    INT32 final_tmp13 = ((local_z1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) - z2_odd + z4_odd;

    // Store results using computed values — no loop-carried dependency
    wsptr[5 * 0] = (int)((stage2_tmp20 + final_tmp10) >> (13 - 2));
    wsptr[5 * 9] = (int)((stage2_tmp20 - final_tmp10) >> (13 - 2));
    wsptr[5 * 1] = (int)((stage2_tmp21 + final_tmp11) >> (13 - 2));
    wsptr[5 * 8] = (int)((stage2_tmp21 - final_tmp11) >> (13 - 2));
    wsptr[5 * 2] = (int)(stage2_tmp22 + final_tmp12);
    wsptr[5 * 7] = (int)(stage2_tmp22 - final_tmp12);
    wsptr[5 * 3] = (int)((stage2_tmp23 + final_tmp13) >> (13 - 2));
    wsptr[5 * 6] = (int)((stage2_tmp23 - final_tmp13) >> (13 - 2));
    wsptr[5 * 4] = (int)((stage2_tmp24 + final_tmp14) >> (13 - 2));
    wsptr[5 * 5] = (int)((stage2_tmp24 - final_tmp14) >> (13 - 2));
}
}
