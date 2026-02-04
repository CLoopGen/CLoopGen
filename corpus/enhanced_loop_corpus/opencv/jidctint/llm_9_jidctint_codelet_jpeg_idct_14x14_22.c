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
for (ctr = 0; ctr < 16; ctr += 2, inptr += 2, quantptr += 2, wsptr += 2) {
    for (int unroll = 0; unroll < 2; ++unroll) {
        if (ctr + unroll >= 8) break;

        INT32 local_z1, local_z2, local_z3, local_z4;
        INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15, local_tmp16;
        INT32 local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25, local_tmp26;

        JCOEFPTR local_inptr = inptr + unroll;
        ISLOW_MULT_TYPE *local_quantptr = quantptr + unroll;
        int *local_wsptr = wsptr + unroll;

        local_z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (local_quantptr[8 * 0]));
        local_z1 <<= 13;
        local_z1 += ((INT32)1) << (13 - 2 - 1);
        local_z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 4])) * (local_quantptr[8 * 4]));
        local_z2 = ((local_z4) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5))));
        local_z3 = ((local_z4) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        local_z4 = ((local_z4) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        local_tmp10 = local_z1 + local_z2;
        local_tmp11 = local_z1 + local_z3;
        local_tmp12 = local_z1 - local_z4;
        local_tmp23 = ((local_z1 - ((local_z2 + local_z3 - local_z4) << 1)) >> (13 - 2));
        local_z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
        local_z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));
        local_z3 = ((local_z1 + local_z2) * (((INT32)((1.105676686) * (((INT32)1) << 13) + 0.5))));
        local_tmp13 = local_z3 + ((local_z1) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5))));
        local_tmp14 = local_z3 - ((local_z2) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5))));
        local_tmp15 = ((local_z1) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5)))) - ((local_z2) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        local_tmp20 = local_tmp10 + local_tmp13;
        local_tmp26 = local_tmp10 - local_tmp13;
        local_tmp21 = local_tmp11 + local_tmp14;
        local_tmp25 = local_tmp11 - local_tmp14;
        local_tmp22 = local_tmp12 + local_tmp15;
        local_tmp24 = local_tmp12 - local_tmp15;
        local_z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 1])) * (local_quantptr[8 * 1]));
        local_z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 3])) * (local_quantptr[8 * 3]));
        local_z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 5])) * (local_quantptr[8 * 5]));
        local_z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 7])) * (local_quantptr[8 * 7]));
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

        local_wsptr[8 * 0] = (int)((local_tmp20 + local_tmp10) >> (13 - 2));
        local_wsptr[8 * 13] = (int)((local_tmp20 - local_tmp10) >> (13 - 2));
        local_wsptr[8 * 1] = (int)((local_tmp21 + local_tmp11) >> (13 - 2));
        local_wsptr[8 * 12] = (int)((local_tmp21 - local_tmp11) >> (13 - 2));
        local_wsptr[8 * 2] = (int)((local_tmp22 + local_tmp12) >> (13 - 2));
        local_wsptr[8 * 11] = (int)((local_tmp22 - local_tmp12) >> (13 - 2));
        local_wsptr[8 * 3] = (int)(local_tmp23 + local_tmp13);
        local_wsptr[8 * 10] = (int)(local_tmp23 - local_tmp13);
        local_wsptr[8 * 4] = (int)((local_tmp24 + local_tmp14) >> (13 - 2));
        local_wsptr[8 * 9] = (int)((local_tmp24 - local_tmp14) >> (13 - 2));
        local_wsptr[8 * 5] = (int)((local_tmp25 + local_tmp15) >> (13 - 2));
        local_wsptr[8 * 8] = (int)((local_tmp25 - local_tmp15) >> (13 - 2));
        local_wsptr[8 * 6] = (int)((local_tmp26 + local_tmp16) >> (13 - 2));
        local_wsptr[8 * 7] = (int)((local_tmp26 - local_tmp16) >> (13 - 2));
    }
}
}
