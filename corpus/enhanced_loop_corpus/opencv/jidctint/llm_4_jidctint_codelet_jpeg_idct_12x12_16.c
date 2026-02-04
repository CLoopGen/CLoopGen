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
for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
    if (ctr % 2 == 0) {
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        z3 = ((JLONG)((unsigned long)(z3) << (13)));
        z3 += ((JLONG)1) << (13 - 1 - 1);
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z4 = ((z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = z3 + z4;
        tmp11 = z3 - z4;
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z4 = ((z1) * (((JLONG)((1.3660254039999999) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((JLONG)((unsigned long)(z1) << (13)));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        z2 = ((JLONG)((unsigned long)(z2) << (13)));
        tmp12 = z1 - z2;
        tmp21 = z3 + tmp12;
        tmp24 = z3 - tmp12;
        tmp12 = z4 + z2;
        tmp20 = tmp10 + tmp12;
        tmp25 = tmp10 - tmp12;
        tmp12 = z4 - z1 - z2;
        tmp22 = tmp11 + tmp12;
        tmp23 = tmp11 - tmp12;
    } else {
        tmp20 = tmp25 = tmp21 = tmp22 = tmp23 = tmp24 = 0;
        tmp10 = tmp11 = tmp12 = tmp13 = tmp14 = tmp15 = 0;
        z1 = z2 = z3 = z4 = 0;
    }

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    tmp11 = ((z2) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2) * (-((JLONG)4433)));
    tmp10 = z1 + z3;
    tmp15 = ((tmp10 + z4) * (((JLONG)((0.86091866900000003) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = tmp15 + ((tmp10) * (((JLONG)((0.26105238400000003) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp12 + tmp11 + ((z1) * (((JLONG)((0.28014371599999999) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((z3 + z4) * (-((JLONG)((1.04551058) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp13 + tmp14 - ((z3) * (((JLONG)((1.478575242) * (((JLONG)1) << 13) + 0.5))));
    tmp13 += tmp15 - tmp11 + ((z4) * (((JLONG)((1.5867066809999999) * (((JLONG)1) << 13) + 0.5))));
    tmp15 += tmp14 - ((z1) * (((JLONG)((0.67632675799999997) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.982889723) * (((JLONG)1) << 13) + 0.5))));
    z1 -= z4;
    z2 -= z3;
    z3 = ((z1 + z2) * (((JLONG)4433)));
    tmp11 = z3 + ((z1) * (((JLONG)6270)));
    tmp14 = z3 - ((z2) * (((JLONG)15137)));

    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 1));
    wsptr[8 * 11] = (int)((tmp20 - tmp10) >> (13 - 1));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 1));
    wsptr[8 * 10] = (int)((tmp21 - tmp11) >> (13 - 1));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 1));
    wsptr[8 * 9] = (int)((tmp22 - tmp12) >> (13 - 1));
    wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 1));
    wsptr[8 * 8] = (int)((tmp23 - tmp13) >> (13 - 1));
    wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 1));
    wsptr[8 * 7] = (int)((tmp24 - tmp14) >> (13 - 1));
    wsptr[8 * 5] = (int)((tmp25 + tmp15) >> (13 - 1));
    wsptr[8 * 6] = (int)((tmp25 - tmp15) >> (13 - 1));
}
}
