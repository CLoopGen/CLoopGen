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
for (ctr = 0; ctr < 7; ctr++ , inptr++ , quantptr++ , wsptr++) {
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 <<= 13;
    z1 += ((INT32)1) << (13 - 2 - 1);
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z2 = ((z4) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5))));
    z3 = ((z4) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
    z4 = ((z4) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z1 + z2;
    tmp11 = z1 + z3;
    tmp12 = z1 - z4;
    tmp23 = ((z1 - ((z2 + z3 - z4) << 1)) >> (13 - 2));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    z3 = ((z1 + z2) * (((INT32)((1.105676686) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z3 + ((z1) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5))));
    tmp14 = z3 - ((z2) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5))));
    tmp15 = ((z1) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5)))) - ((z2) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
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
    tmp13 = z4 << 13;
    tmp14 = z1 + z3;
    tmp11 = ((z1 + z2) * (((INT32)((1.334852607) * (((INT32)1) << 13) + 0.5))));
    tmp12 = ((tmp14) * (((INT32)((1.1974488459999999) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5))));
    tmp14 = ((tmp14) * (((INT32)((0.752406978) * (((INT32)1) << 13) + 0.5))));
    tmp16 = tmp14 - ((z1) * (((INT32)((1.061150426) * (((INT32)1) << 13) + 0.5))));
    z1 -= z2;
    tmp15 = ((z1) * (((INT32)((0.46708512899999999) * (((INT32)1) << 13) + 0.5)))) - tmp13;
    tmp16 += tmp15;
    z1 += z4;
    z4 = ((z2 + z3) * (-((INT32)((0.15834168100000001) * (((INT32)1) << 13) + 0.5)))) - tmp13;
    tmp11 += z4 - ((z2) * (((INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5))));
    tmp12 += z4 - ((z3) * (((INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5))));
    z4 = ((z3 - z2) * (((INT32)((1.405321284) * (((INT32)1) << 13) + 0.5))));
    tmp14 += z4 + tmp13 - ((z3) * (((INT32)((1.6906431334000001) * (((INT32)1) << 13) + 0.5))));
    tmp15 += z4 + ((z2) * (((INT32)((0.67495756699999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = (z1 - z3) << 2;
    wsptr[7 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[7 * 13] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[7 * 1] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[7 * 12] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[7 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[7 * 11] = (int)((tmp22 - tmp12) >> (13 - 2));
    wsptr[7 * 3] = (int)(tmp23 + tmp13);
    wsptr[7 * 10] = (int)(tmp23 - tmp13);
    wsptr[7 * 4] = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[7 * 9] = (int)((tmp24 - tmp14) >> (13 - 2));
    wsptr[7 * 5] = (int)((tmp25 + tmp15) >> (13 - 2));
    wsptr[7 * 8] = (int)((tmp25 - tmp15) >> (13 - 2));
    wsptr[7 * 6] = (int)((tmp26 + tmp16) >> (13 - 2));
    wsptr[7 * 7] = (int)((tmp26 - tmp16) >> (13 - 2));
}

}
