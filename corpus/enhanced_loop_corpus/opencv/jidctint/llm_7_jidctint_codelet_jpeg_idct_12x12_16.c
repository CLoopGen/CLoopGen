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
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
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
for (ctr = 0; ctr < 8; ctr++, inptr++ , quantptr++ , wsptr++) {
    JLONG local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15;
    JLONG local_z1, local_z2, local_z3, local_z4;
    JLONG local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25;

    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_z3 = ((JLONG)((unsigned long)(local_z3) << (13)));
    local_z3 += ((JLONG)1) << (13 - 1 - 1);
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_z4 = ((local_z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
    local_tmp10 = local_z3 + local_z4;
    local_tmp11 = local_z3 - local_z4;

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_z4 = ((local_z1) * (((JLONG)((1.3660254039999999) * (((JLONG)1) << 13) + 0.5))));
    local_z1 = ((JLONG)((unsigned long)(local_z1) << (13)));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_z2 = ((JLONG)((unsigned long)(local_z2) << (13)));
    local_tmp12 = local_z1 - local_z2;
    local_tmp21 = local_z3 + local_tmp12;
    local_tmp24 = local_z3 - local_tmp12;
    local_tmp12 = local_z4 + local_z2;
    local_tmp20 = local_tmp10 + local_tmp12;
    local_tmp25 = local_tmp10 - local_tmp12;
    local_tmp12 = local_z4 - local_z1 - local_z2;
    local_tmp22 = local_tmp11 + local_tmp12;
    local_tmp23 = local_tmp11 - local_tmp12;

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    local_tmp11 = ((local_z2) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
    local_tmp14 = ((local_z2) * (-((JLONG)4433)));
    local_tmp10 = local_z1 + local_z3;
    local_tmp15 = ((local_tmp10 + local_z4) * (((JLONG)((0.86091866900000003) * (((JLONG)1) << 13) + 0.5))));

    local_tmp12 = local_tmp15 + ((local_tmp10) * (((JLONG)((0.26105238400000003) * (((JLONG)1) << 13) + 0.5))));
    local_tmp10 = local_tmp12 + local_tmp11 + ((local_z1) * (((JLONG)((0.28014371599999999) * (((JLONG)1) << 13) + 0.5))));
    local_tmp13 = ((local_z3 + local_z4) * (-((JLONG)((1.04551058) * (((JLONG)1) << 13) + 0.5))));
    local_tmp12 += local_tmp13 + local_tmp14 - ((local_z3) * (((JLONG)((1.478575242) * (((JLONG)1) << 13) + 0.5))));
    local_tmp13 += local_tmp15 - local_tmp11 + ((local_z4) * (((JLONG)((1.5867066809999999) * (((JLONG)1) << 13) + 0.5))));
    local_tmp15 += local_tmp14 - ((local_z1) * (((JLONG)((0.67632675799999997) * (((JLONG)1) << 13) + 0.5)))) - ((local_z4) * (((JLONG)((1.982889723) * (((JLONG)1) << 13) + 0.5))));

    local_z1 -= local_z4;
    local_z2 -= local_z3;
    local_z3 = ((local_z1 + local_z2) * (((JLONG)4433)));
    local_tmp11 = local_z3 + ((local_z1) * (((JLONG)6270)));
    local_tmp14 = local_z3 - ((local_z2) * (((JLONG)15137)));

    wsptr[8 * 0] = (int)((local_tmp20 + local_tmp10) >> (13 - 1));
    wsptr[8 * 11] = (int)((local_tmp20 - local_tmp10) >> (13 - 1));
    wsptr[8 * 1] = (int)((local_tmp21 + local_tmp11) >> (13 - 1));
    wsptr[8 * 10] = (int)((local_tmp21 - local_tmp11) >> (13 - 1));
    wsptr[8 * 2] = (int)((local_tmp22 + local_tmp12) >> (13 - 1));
    wsptr[8 * 9] = (int)((local_tmp22 - local_tmp12) >> (13 - 1));
    wsptr[8 * 3] = (int)((local_tmp23 + local_tmp13) >> (13 - 1));
    wsptr[8 * 8] = (int)((local_tmp23 - local_tmp13) >> (13 - 1));
    wsptr[8 * 4] = (int)((local_tmp24 + local_tmp14) >> (13 - 1));
    wsptr[8 * 7] = (int)((local_tmp24 - local_tmp14) >> (13 - 1));
    wsptr[8 * 5] = (int)((local_tmp25 + local_tmp15) >> (13 - 1));
    wsptr[8 * 6] = (int)((local_tmp25 - local_tmp15) >> (13 - 1));
}
}
