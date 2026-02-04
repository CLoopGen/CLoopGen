#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
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
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Variant: Eliminate loop-carried dependencies by isolating computation per iteration
    // All temporary variables are now local to the iteration, removing external WAW/RAW hazards

    INT32 local_tmp0, local_tmp1, local_tmp2, local_tmp3;
    INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13;
    INT32 local_tmp20, local_tmp21, local_tmp22, local_tmp23;
    INT32 local_tmp24, local_tmp25, local_tmp26, local_tmp27;
    INT32 local_z1, local_z2, local_z3, local_z4;

    // First stage: DC and low-frequency AC coefficients
    local_tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_tmp0 <<= 13;
    local_tmp0 += ((INT32)1) << (13 - 2 - 1);
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_tmp1 = ((local_z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
    local_tmp2 = ((local_z1) * (((INT32)4433)));
    local_tmp10 = local_tmp0 + local_tmp1;
    local_tmp11 = local_tmp0 - local_tmp1;
    local_tmp12 = local_tmp0 + local_tmp2;
    local_tmp13 = local_tmp0 - local_tmp2;

    // Mid-frequency butterfly
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_z3 = local_z1 - local_z2;
    local_z4 = ((local_z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
    local_z3 = ((local_z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp0 = local_z3 + ((local_z2) * (((INT32)20995)));
    local_tmp1 = local_z4 + ((local_z1) * (((INT32)7373)));
    local_tmp2 = local_z3 - ((local_z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
    local_tmp3 = local_z4 - ((local_z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));
    local_tmp20 = local_tmp10 + local_tmp0;
    local_tmp27 = local_tmp10 - local_tmp0;
    local_tmp21 = local_tmp12 + local_tmp1;
    local_tmp26 = local_tmp12 - local_tmp1;
    local_tmp22 = local_tmp13 + local_tmp2;
    local_tmp25 = local_tmp13 - local_tmp2;
    local_tmp23 = local_tmp11 + local_tmp3;
    local_tmp24 = local_tmp11 - local_tmp3;

    // High-frequency inputs
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    local_tmp11 = local_z1 + local_z3;
    local_tmp1 = ((local_z1 + local_z2) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp2 = ((local_tmp11) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    local_tmp3 = ((local_z1 + local_z4) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp10 = ((local_z1 - local_z4) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
    local_tmp11 = ((local_tmp11) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 = ((local_z1 - local_z2) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    local_tmp0 = local_tmp1 + local_tmp2 + local_tmp3 - ((local_z1) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = local_tmp10 + local_tmp11 + local_tmp12 - ((local_z1) * (((INT32)((1.835730603) * (((INT32)1) << 13) + 0.5))));

    // Cross-term interactions
    local_z1 = ((local_z2 + local_z3) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp1 += local_z1 + ((local_z2) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5))));
    local_tmp2 += local_z1 - ((local_z3) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5))));
    local_z1 = ((local_z3 - local_z2) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
    local_tmp11 += local_z1 - ((local_z3) * (((INT32)((0.76636728200000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 += local_z1 + ((local_z2) * (((INT32)((1.971951411) * (((INT32)1) << 13) + 0.5))));
    local_z2 += local_z4;
    local_z1 = ((local_z2) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp1 += local_z1;
    local_tmp3 += local_z1 + ((local_z4) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5))));
    local_z2 = ((local_z2) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    local_tmp10 += local_z2 + ((local_z4) * (((INT32)((3.141271809) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 += local_z2;
    local_z2 = ((local_z3 + local_z4) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp2 += local_z2;
    local_tmp3 += local_z2;
    local_z2 = ((local_z4 - local_z3) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    local_tmp10 += local_z2;
    local_tmp11 += local_z2;

    // Store results using direct indexing with no reuse of global temps
    wsptr[8 * 0] = (int)((local_tmp20 + local_tmp0) >> (13 - 2));
    wsptr[8 * 15] = (int)((local_tmp20 - local_tmp0) >> (13 - 2));
    wsptr[8 * 1] = (int)((local_tmp21 + local_tmp1) >> (13 - 2));
    wsptr[8 * 14] = (int)((local_tmp21 - local_tmp1) >> (13 - 2));
    wsptr[8 * 2] = (int)((local_tmp22 + local_tmp2) >> (13 - 2));
    wsptr[8 * 13] = (int)((local_tmp22 - local_tmp2) >> (13 - 2));
    wsptr[8 * 3] = (int)((local_tmp23 + local_tmp3) >> (13 - 2));
    wsptr[8 * 12] = (int)((local_tmp23 - local_tmp3) >> (13 - 2));
    wsptr[8 * 4] = (int)((local_tmp24 + local_tmp10) >> (13 - 2));
    wsptr[8 * 11] = (int)((local_tmp24 - local_tmp10) >> (13 - 2));
    wsptr[8 * 5] = (int)((local_tmp25 + local_tmp11) >> (13 - 2));
    wsptr[8 * 10] = (int)((local_tmp25 - local_tmp11) >> (13 - 2));
    wsptr[8 * 6] = (int)((local_tmp26 + local_tmp12) >> (13 - 2));
    wsptr[8 * 9] = (int)((local_tmp26 - local_tmp12) >> (13 - 2));
    wsptr[8 * 7] = (int)((local_tmp27 + local_tmp13) >> (13 - 2));
    wsptr[8 * 8] = (int)((local_tmp27 - local_tmp13) >> (13 - 2));
}
}
