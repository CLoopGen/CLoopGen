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
for (ctr = 0; ctr < 4; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));
    z1 += ((JLONG)1) << (13 - 1 - 1);
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z2 = ((z4) * (((JLONG)((1.274162392) * (((JLONG)1) << 13) + 0.5))));
    z3 = ((z4) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
    z4 = ((z4) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = z1 + z2;
    tmp11 = z1 + z3;
    tmp12 = z1 - z4;
    tmp23 = ((z1 - ((JLONG)((unsigned long)(z2 + z3 - z4) << (1)))) >> (13 - 1));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    z3 = ((z1 + z2) * (((JLONG)((1.105676686) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = z3 + ((z1) * (((JLONG)((0.27307958999999998) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = z3 - ((z2) * (((JLONG)((1.719280954) * (((JLONG)1) << 13) + 0.5))));
    tmp15 = ((z1) * (((JLONG)((0.61360426800000001) * (((JLONG)1) << 13) + 0.5)))) - ((z2) * (((JLONG)((1.3787562760000001) * (((JLONG)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp13;
    tmp26 = tmp10 - tmp13;
    tmp21 = tmp11 + tmp14;
    tmp25 = tmp11 - tmp14;
    tmp22 = tmp12 + tmp15;
    tmp24 = tmp12 - tmp15;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    tmp13 = ((JLONG)((unsigned long)(z4) << (13)));
    tmp14 = z1 + z3;
    tmp11 = ((z1 + z2) * (((JLONG)((1.334852607) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((tmp14) * (((JLONG)((1.1974488459999999) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((1.1269801690000001) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((tmp14) * (((JLONG)((0.752406978) * (((JLONG)1) << 13) + 0.5))));
    tmp16 = tmp14 - ((z1) * (((JLONG)((1.061150426) * (((JLONG)1) << 13) + 0.5))));
    z1 -= z2;
    tmp15 = ((z1) * (((JLONG)((0.46708512899999999) * (((JLONG)1) << 13) + 0.5)))) - tmp13;
    tmp16 += tmp15;
    z1 += z4;
    z4 = ((z2 + z3) * (-((JLONG)((0.15834168100000001) * (((JLONG)1) << 13) + 0.5)))) - tmp13;
    tmp11 += z4 - ((z2) * (((JLONG)((0.42410394800000001) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += z4 - ((z3) * (((JLONG)((2.3739597730000002) * (((JLONG)1) << 13) + 0.5))));
    z4 = ((z3 - z2) * (((JLONG)((1.405321284) * (((JLONG)1) << 13) + 0.5))));
    tmp14 += z4 + tmp13 - ((z3) * (((JLONG)((1.6906431334000001) * (((JLONG)1) << 13) + 0.5))));
    tmp15 += z4 + ((z2) * (((JLONG)((0.67495756699999998) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((JLONG)((unsigned long)(z1 - z3) << (1)));
    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 1));
    wsptr[8 * 13] = (int)((tmp20 - tmp10) >> (13 - 1));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 1));
    wsptr[8 * 12] = (int)((tmp21 - tmp11) >> (13 - 1));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 1));
    wsptr[8 * 11] = (int)((tmp22 - tmp12) >> (13 - 1));
    wsptr[8 * 3] = (int)(tmp23 + tmp13);
    wsptr[8 * 10] = (int)(tmp23 - tmp13);
    wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 1));
    wsptr[8 * 9] = (int)((tmp24 - tmp14) >> (13 - 1));
    wsptr[8 * 5] = (int)((tmp25 + tmp15) >> (13 - 1));
    wsptr[8 * 8] = (int)((tmp25 - tmp15) >> (13 - 1));
    wsptr[8 * 6] = (int)((tmp26 + tmp16) >> (13 - 1));
    wsptr[8 * 7] = (int)((tmp26 - tmp16) >> (13 - 1));
}
}
