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
for (ctr = 0; ctr < 16; ctr += 2, inptr += 2, quantptr += 2, wsptr += 2) {
    for (int unroll_factor = 0; unroll_factor < 2; ++unroll_factor) {
        int offset = unroll_factor * 8;
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 0])) * (quantptr[offset + 8 * 0]));
        tmp0 <<= 13;
        tmp0 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 4])) * (quantptr[offset + 8 * 4]));
        tmp1 = ((z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((INT32)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 2])) * (quantptr[offset + 8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 6])) * (quantptr[offset + 8 * 6]));
        z3 = z1 - z2;
        z4 = ((z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
        z3 = ((z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = z3 + ((z2) * (((INT32)20995)));
        tmp1 = z4 + ((z1) * (((INT32)7373)));
        tmp2 = z3 - ((z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
        tmp3 = z4 - ((z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp0;
        tmp27 = tmp10 - tmp0;
        tmp21 = tmp12 + tmp1;
        tmp26 = tmp12 - tmp1;
        tmp22 = tmp13 + tmp2;
        tmp25 = tmp13 - tmp2;
        tmp23 = tmp11 + tmp3;
        tmp24 = tmp11 - tmp3;
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 1])) * (quantptr[offset + 8 * 1]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 3])) * (quantptr[offset + 8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 5])) * (quantptr[offset + 8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[offset + 8 * 7])) * (quantptr[offset + 8 * 7]));
        tmp11 = z1 + z3;
        tmp1 = ((z1 + z2) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp11) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 = ((z1 - z4) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 + tmp2 + tmp3 - ((z1) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5))));
        tmp13 = tmp10 + tmp11 + tmp12 - ((z1) * (((INT32)((1.835730603) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z2 + z3) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5))));
        tmp1 += z1 + ((z2) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z1 - ((z3) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z3 - z2) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1 - ((z3) * (((INT32)((0.76636728200000004) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z1 + ((z2) * (((INT32)((1.971951411) * (((INT32)1) << 13) + 0.5))));
        z2 += z4;
        z1 = ((z2) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp1 += z1;
        tmp3 += z1 + ((z4) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5))));
        z2 = ((z2) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2 + ((z4) * (((INT32)((3.141271809) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z2;
        z2 = ((z3 + z4) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z2;
        tmp3 += z2;
        z2 = ((z4 - z3) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp11 += z2;
        wsptr[offset + 8 * 0] = (int)((tmp20 + tmp0) >> (13 - 2));
        wsptr[offset + 8 * 15] = (int)((tmp20 - tmp0) >> (13 - 2));
        wsptr[offset + 8 * 1] = (int)((tmp21 + tmp1) >> (13 - 2));
        wsptr[offset + 8 * 14] = (int)((tmp21 - tmp1) >> (13 - 2));
        wsptr[offset + 8 * 2] = (int)((tmp22 + tmp2) >> (13 - 2));
        wsptr[offset + 8 * 13] = (int)((tmp22 - tmp2) >> (13 - 2));
        wsptr[offset + 8 * 3] = (int)((tmp23 + tmp3) >> (13 - 2));
        wsptr[offset + 8 * 12] = (int)((tmp23 - tmp3) >> (13 - 2));
        wsptr[offset + 8 * 4] = (int)((tmp24 + tmp10) >> (13 - 2));
        wsptr[offset + 8 * 11] = (int)((tmp24 - tmp10) >> (13 - 2));
        wsptr[offset + 8 * 5] = (int)((tmp25 + tmp11) >> (13 - 2));
        wsptr[offset + 8 * 10] = (int)((tmp25 - tmp11) >> (13 - 2));
        wsptr[offset + 8 * 6] = (int)((tmp26 + tmp12) >> (13 - 2));
        wsptr[offset + 8 * 9] = (int)((tmp26 - tmp12) >> (13 - 2));
        wsptr[offset + 8 * 7] = (int)((tmp27 + tmp13) >> (13 - 2));
        wsptr[offset + 8 * 8] = (int)((tmp27 - tmp13) >> (13 - 2));
    }
}
}
