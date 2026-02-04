#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp13 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp13 = ((JLONG)((unsigned long)(tmp13) << (13)));
    tmp13 += ((JLONG)1) << (13 - 1 - 1);

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

    if (z2 != 0) {
        tmp10 = ((z2 - z3) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp10 + tmp12 + tmp13 - ((z2) * (((JLONG)((1.841218003) * (((JLONG)1) << 13) + 0.5))));
    } else {
        tmp10 = ((z3) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp10 - tmp12 + tmp13;
    }

    tmp0 = z1 + z3;
    z2 -= tmp0;
    tmp0 = ((tmp0) * (((JLONG)((1.274162392) * (((JLONG)1) << 13) + 0.5)))) + tmp13;

    if (z3 > 0) {
        tmp10 += tmp0 - ((z3) * (((JLONG)((0.077722535999999995) * (((JLONG)1) << 13) + 0.5))));
    } else {
        tmp10 += tmp0 + ((z3) * (((JLONG)((0.077722535999999995) * (((JLONG)1) << 13) + 0.5))));
    }

    if (z1 != 0) {
        tmp12 += tmp0 - ((z1) * (((JLONG)((2.4706022490000001) * (((JLONG)1) << 13) + 0.5))));
    } else {
        tmp12 += tmp0;
    }

    tmp13 += ((z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));

    tmp1 = ((z1 + z2) * (((JLONG)((0.93541434700000003) * (((JLONG)1) << 13) + 0.5))));
    tmp2 = ((z1 - z2) * (((JLONG)((0.17026233900000001) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = tmp1 - tmp2;
    tmp1 += tmp2;

    tmp2 = ((z2 + z3) * (-((JLONG)((1.3787562760000001) * (((JLONG)1) << 13) + 0.5))));
    tmp1 += tmp2;

    z2 = ((z1 + z3) * (((JLONG)((0.61360426800000001) * (((JLONG)1) << 13) + 0.5))));
    tmp0 += z2;
    tmp2 += z2 + ((z3) * (((JLONG)((1.870828693) * (((JLONG)1) << 13) + 0.5))));

    wsptr[7 * 0] = (int)((tmp10 + tmp0) >> (13 - 1));
    wsptr[7 * 6] = (int)((tmp10 - tmp0) >> (13 - 1));
    wsptr[7 * 1] = (int)((tmp11 + tmp1) >> (13 - 1));
    wsptr[7 * 5] = (int)((tmp11 - tmp1) >> (13 - 1));
    wsptr[7 * 2] = (int)((tmp12 + tmp2) >> (13 - 1));
    wsptr[7 * 4] = (int)((tmp12 - tmp2) >> (13 - 1));
    wsptr[7 * 3] = (int)((tmp13) >> (13 - 1));
}
}
