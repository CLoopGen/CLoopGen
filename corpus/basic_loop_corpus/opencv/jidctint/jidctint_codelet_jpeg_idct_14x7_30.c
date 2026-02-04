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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp23 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp23 <<= 13;
    tmp23 += ((INT32)1) << (13 - 2 - 1);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp20 = ((z2 - z3) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
    tmp22 = ((z1 - z2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
    tmp21 = tmp20 + tmp22 + tmp23 - ((z2) * (((INT32)((1.841218003) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z1 + z3;
    z2 -= tmp10;
    tmp10 = ((tmp10) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + tmp23;
    tmp20 += tmp10 - ((z3) * (((INT32)((0.077722535999999995) * (((INT32)1) << 13) + 0.5))));
    tmp22 += tmp10 - ((z1) * (((INT32)((2.4706022490000001) * (((INT32)1) << 13) + 0.5))));
    tmp23 += ((z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp11 = ((z1 + z2) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
    tmp12 = ((z1 - z2) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp11 - tmp12;
    tmp11 += tmp12;
    tmp12 = ((z2 + z3) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
    tmp11 += tmp12;
    z2 = ((z1 + z3) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
    tmp10 += z2;
    tmp12 += z2 + ((z3) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));
    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[8 * 6] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[8 * 5] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[8 * 4] = (int)((tmp22 - tmp12) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp23) >> (13 - 2));
}

}
