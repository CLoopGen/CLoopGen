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
    // Reorder computations to eliminate some false dependencies and introduce parallelism
    INT32 local_tmp0, local_tmp1, local_tmp2, local_z1, local_z2, local_z3, local_z4;
    INT32 stage1[8], stage2[8], stage3[8]; // Break long dependency chains with intermediate staging

    // Load and scale early coefficients independently
    local_tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 13;
    local_tmp0 += ((INT32)1) << (13 - 2 - 1);

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    stage1[0] = ((local_z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
    stage1[1] = ((local_z1) * (((INT32)4433)));

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_z3 = local_z1 - local_z2;
    stage1[2] = ((local_z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
    stage1[3] = ((local_z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));

    // Compute independent terms in parallel
    stage2[0] = stage1[3] + ((local_z2) * (((INT32)20995)));
    stage2[1] = stage1[2] + ((local_z1) * (((INT32)7373)));
    stage2[2] = stage1[3] - ((local_z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
    stage2[3] = stage1[2] - ((local_z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));

    // Stage 1 outputs combined with initial tmp values
    INT32 tmp10 = local_tmp0 + stage1[0];
    INT32 tmp11 = local_tmp0 - stage1[0];
    INT32 tmp12 = local_tmp0 + stage1[1];
    INT32 tmp13 = local_tmp0 - stage1[1];

    // Continue with other inputs without reusing z1 too early (avoid WAW)
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    INT32 sum_13 = local_z1 + local_z3;
    stage3[0] = ((local_z1 + local_z2) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
    stage3[1] = ((sum_13) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    stage3[2] = ((local_z1 + local_z4) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5))));
    stage3[3] = ((local_z1 - local_z4) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
    stage3[4] = ((sum_13) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    stage3[5] = ((local_z1 - local_z2) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));

    // Finalize stages with reduced inter-variable dependencies
    INT32 final_tmp0 = stage3[0] + stage3[1] + stage3[2] - ((local_z1) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5))));
    INT32 final_tmp13 = stage3[3] + stage3[4] + stage3[5] - ((local_z1) * (((INT32)((1.835730603) * (((INT32)1) << 13) + 0.5))));

    // Combine results using staged intermediates to minimize live range overlap
    wsptr[8 * 0] = (int)((tmp10 + stage2[0] + final_tmp0) >> (13 - 2));  // Merged path
    wsptr[8 * 15] = (int)((tmp10 - stage2[0]) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp12 + stage2[1] + stage3[0]) >> (13 - 2));
    wsptr[8 * 14] = (int)((tmp12 - stage2[1]) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp13 + stage2[2] + stage3[1]) >> (13 - 2));
    wsptr[8 * 13] = (int)((tmp13 - stage2[2]) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp11 + stage2[3] + stage3[2]) >> (13 - 2));
    wsptr[8 * 12] = (int)((tmp11 - stage2[3]) >> (13 - 2));

    // Remaining outputs adjusted accordingly
    wsptr[8 * 4] = (int)((tmp11 - stage2[3] + stage3[3]) >> (13 - 2));  // example reuse
    wsptr[8 * 11] = (int)((tmp11 - stage2[3] - stage3[3]) >> (13 - 2));
    wsptr[8 * 5] = (int)((tmp13 - stage2[2] + stage3[4]) >> (13 - 2));
    wsptr[8 * 10] = (int)((tmp13 - stage2[2] - stage3[4]) >> (13 - 2));
    wsptr[8 * 6] = (int)((tmp12 - stage2[1] + stage3[5]) >> (13 - 2));
    wsptr[8 * 9] = (int)((tmp12 - stage2[1] - stage3[5]) >> (13 - 2));
    wsptr[8 * 7] = (int)((tmp10 - stage2[0] + final_tmp13) >> (13 - 2));
    wsptr[8 * 8] = (int)((tmp10 - stage2[0] - final_tmp13) >> (13 - 2));
}
}
