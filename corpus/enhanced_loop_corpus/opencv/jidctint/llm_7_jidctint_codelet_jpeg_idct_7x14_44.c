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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies by privatizing key variables and reordering independent operations
for (ctr = 0; ctr < 7; ctr++, inptr++, quantptr++, wsptr++) {
    INT32 local_z1, local_z2, local_z3, local_z4;
    INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15, local_tmp16;
    INT32 local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25, local_tmp26;

    // Reorder computations to expose parallelism and remove artificial ordering constraints
    // Start with diagonal elements that don't depend on others
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_z1 <<= 13;
    local_z1 += ((INT32)1) << (13 - 2 - 1);

    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_z2 = ((local_z4) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5))));
    local_z3 = ((local_z4) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
    local_z4 = ((local_z4) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));

    // Compute early sums independently
    local_tmp10 = local_z1 + local_z2;
    local_tmp11 = local_z1 + local_z3;
    local_tmp12 = local_z1 - local_z4;
    local_tmp23 = ((local_z1 - ((local_z2 + local_z3 - local_z4) << 1)) >> (13 - 2));

    // Break dependency chain by computing second block before finishing first
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    // Interleave independent computations from different stages
    INT32 t_z1_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    INT32 t_z2_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    INT32 t_z3_2 = ((t_z1_2 + t_z2_2) * (((INT32)((1.105676686) * (((INT32)1) << 13) + 0.5))));

    // Complete stage 1 now
    local_tmp13 = t_z3_2 + ((t_z1_2) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = t_z3_2 - ((t_z2_2) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5))));
    local_tmp15 = ((t_z1_2) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5)))) - ((t_z2_2) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));

    // Combine stage 1 results
    local_tmp20 = local_tmp10 + local_tmp13;
    local_tmp26 = local_tmp10 - local_tmp13;
    local_tmp21 = local_tmp11 + local_tmp14;
    local_tmp25 = local_tmp11 - local_tmp14;
    local_tmp22 = local_tmp12 + local_tmp15;
    local_tmp24 = local_tmp12 - local_tmp15;

    // Complete stage 2 using interleaved values
    local_tmp13 = local_z4 << 13;
    local_tmp14 = local_z1 + local_z3;
    local_tmp11 = ((local_z1 + local_z2) * (((INT32)((1.334852607) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 = ((local_tmp14) * (((INT32)((1.1974488459999999) * (((INT32)1) << 13) + 0.5))));
    local_tmp10 = local_tmp11 + local_tmp12 + local_tmp13 - ((local_z1) * (((INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = ((local_tmp14) * (((INT32)((0.752406978) * (((INT32)1) << 13) + 0.5))));
    local_tmp16 = local_tmp14 - ((local_z1) * (((INT32)((1.061150426) * (((INT32)1) << 13) + 0.5))));
    local_z1 -= local_z2;
    local_tmp15 = ((local_z1) * (((INT32)((0.46708512899999999) * (((INT32)1) << 13) + 0.5)))) - local_tmp13;
    local_tmp16 += local_tmp15;
    local_z1 += local_z4;
    local_z4 = ((local_z2 + local_z3) * (-((INT32)((0.15834168100000001) * (((INT32)1) << 13) + 0.5)))) - local_tmp13;
    local_tmp11 += local_z4 - ((local_z2) * (((INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 += local_z4 - ((local_z3) * (((INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5))));
    local_z4 = ((local_z3 - local_z2) * (((INT32)((1.405321284) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 += local_z4 + local_tmp13 - ((local_z3) * (((INT32)((1.6906431334000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp15 += local_z4 + ((local_z2) * (((INT32)((0.67495756699999998) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = (local_z1 - local_z3) << 2;

    // Store results using local temporaries to eliminate cross-iteration effects
    wsptr[7 * 0] = (int)((local_tmp20 + local_tmp10) >> (13 - 2));
    wsptr[7 * 13] = (int)((local_tmp20 - local_tmp10) >> (13 - 2));
    wsptr[7 * 1] = (int)((local_tmp21 + local_tmp11) >> (13 - 2));
    wsptr[7 * 12] = (int)((local_tmp21 - local_tmp11) >> (13 - 2));
    wsptr[7 * 2] = (int)((local_tmp22 + local_tmp12) >> (13 - 2));
    wsptr[7 * 11] = (int)((local_tmp22 - local_tmp12) >> (13 - 2));
    wsptr[7 * 3] = (int)(local_tmp23 + local_tmp13);
    wsptr[7 * 10] = (int)(local_tmp23 - local_tmp13);
    wsptr[7 * 4] = (int)((local_tmp24 + local_tmp14) >> (13 - 2));
    wsptr[7 * 9] = (int)((local_tmp24 - local_tmp14) >> (13 - 2));
    wsptr[7 * 5] = (int)((local_tmp25 + local_tmp15) >> (13 - 2));
    wsptr[7 * 8] = (int)((local_tmp25 - local_tmp15) >> (13 - 2));
    wsptr[7 * 6] = (int)((local_tmp26 + local_tmp16) >> (13 - 2));
    wsptr[7 * 7] = (int)((local_tmp26 - local_tmp16) >> (13 - 2));
}
}
