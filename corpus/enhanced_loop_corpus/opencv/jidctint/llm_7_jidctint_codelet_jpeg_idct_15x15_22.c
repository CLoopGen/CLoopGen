#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp15;
extern JLONG tmp16;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG tmp27;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Eliminate some temporary variables and inline expressions to reduce WAW and WAR hazards
    // Reorder independent computations to expose parallelism

    JLONG local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_z1 = ((JLONG)((unsigned long)(local_z1) << 13)) + ((JLONG)1) << (12);

    JLONG local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    JLONG local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    JLONG local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

    // Precompute constants outside repeated use
    const JLONG c0 = ((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5));
    const JLONG c1 = ((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5));
    const JLONG c2 = ((JLONG)((1.33762899) * (((JLONG)1) << 13) + 0.5));
    const JLONG c3 = ((JLONG)((0.045680613000000002) * (((JLONG)1) << 13) + 0.5));
    const JLONG c4 = ((JLONG)((1.4397739460000001) * (((JLONG)1) << 13) + 0.5));
    const JLONG c5 = ((JLONG)((0.54705957400000005) * (((JLONG)1) << 13) + 0.5));
    const JLONG c6 = ((JLONG)((0.39923400399999998) * (((JLONG)1) << 13) + 0.5));
    const JLONG c7 = ((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5));
    const JLONG c8 = ((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5));

    JLONG t10 = local_z4 * c0;
    JLONG t11 = local_z4 * c1;
    JLONG t12 = local_z1 - t10;
    JLONG t13 = local_z1 + t11;
    local_z1 -= ((JLONG)((unsigned long)(t11 - t10) << 1));

    JLONG diff_z2_z3 = local_z2 - local_z3;
    JLONG sum_z2_z3 = local_z2 + local_z3;

    JLONG partA = sum_z2_z3 * c2;
    JLONG partB = diff_z2_z3 * c3;
    JLONG scaled_z2 = local_z2 * c4;

    JLONG out20 = t13 + partA + partB;
    JLONG out23 = t12 - partA + partB + scaled_z2;

    JLONG partC = sum_z2_z3 * c5;
    JLONG partD = diff_z2_z3 * c6;
    JLONG out25 = t13 - partC - partD;
    JLONG out26 = t12 + partC - partD - scaled_z2;

    JLONG partE = sum_z2_z3 * c7;
    JLONG partF = diff_z2_z3 * c8;
    JLONG out21 = t12 + partE + partF;
    JLONG out24 = t13 - partE + partF;

    partF += partF;
    JLONG out22 = local_z1 + partF;
    JLONG out27 = local_z1 - partF - partF;

    // Now process odd-indexed inputs without reusing same temporaries immediately
    JLONG o1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    JLONG o3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    JLONG o5 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    JLONG o7 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    JLONG temp_diff = o3 - o7;
    JLONG temp_sum = o1 + temp_diff;

    const JLONG d1 = ((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5));
    const JLONG d2 = ((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5));
    const JLONG d3 = ((JLONG)((1.344997024) * (((JLONG)1) << 13) + 0.5));
    const JLONG d4 = ((JLONG)((1.4064663529999999) * (((JLONG)1) << 13) + 0.5));
    const JLONG d5 = ((JLONG)((2.4574318439999998) * (((JLONG)1) << 13) + 0.5));
    const JLONG d6 = ((JLONG)((1.11243482) * (((JLONG)1) << 13) + 0.5));
    const JLONG d7 = ((JLONG)((0.575212477) * (((JLONG)1) << 13) + 0.5));
    const JLONG d8 = ((JLONG)((0.47575301399999997) * (((JLONG)1) << 13) + 0.5));
    const JLONG d9 = ((JLONG)((0.86924400999999996) * (((JLONG)1) << 13) + 0.5));
    const JLONG d10 = ((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5));

    JLONG p15 = temp_sum * d1;
    JLONG p11 = p15 + (o1 * ((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5)));
    JLONG p14 = p15 - (temp_diff * d2);
    JLONG p13 = o3 * (-d1);
    JLONG p15_neg = o3 * (-d3);

    JLONG z2_minus_z4 = o1 - o7;
    JLONG t12_val = (o5 * d10) + (z2_minus_z4 * d4);
    JLONG t10_val = t12_val + (o7 * d5) - p15_neg;
    JLONG t16_val = t12_val - (o1 * d6) + p13;

    JLONG t12_new = (z2_minus_z4 * d10) - (o5 * d10);
    JLONG z2_sum = (o1 + o7) * d7;
    p13 += z2_sum + (o1 * d8) - (o5 * d10);
    p15_neg += z2_sum - (o7 * d9) + (o5 * d10);

    // Write outputs using computed values directly, avoiding redundant temporaries
    wsptr[8 * 0] = (int)((out20 + t10_val) >> 12);
    wsptr[8 * 14] = (int)((out20 - t10_val) >> 12);
    wsptr[8 * 1] = (int)((out21 + p11) >> 12);
    wsptr[8 * 13] = (int)((out21 - p11) >> 12);
    wsptr[8 * 2] = (int)((out22 + t12_new) >> 12);
    wsptr[8 * 12] = (int)((out22 - t12_new) >> 12);
    wsptr[8 * 3] = (int)((out23 + p13) >> 12);
    wsptr[8 * 11] = (int)((out23 - p13) >> 12);
    wsptr[8 * 4] = (int)((out24 + p14) >> 12);
    wsptr[8 * 10] = (int)((out24 - p14) >> 12);
    wsptr[8 * 5] = (int)((out25 + p15_neg) >> 12);
    wsptr[8 * 9] = (int)((out25 - p15_neg) >> 12);
    wsptr[8 * 6] = (int)((out26 + t16_val) >> 12);
    wsptr[8 * 8] = (int)((out26 - t16_val) >> 12);
    wsptr[8 * 7] = (int)(out27 >> 12);
}
}
