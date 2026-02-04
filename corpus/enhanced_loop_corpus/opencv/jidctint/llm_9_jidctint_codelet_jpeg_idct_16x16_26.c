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
for (ctr = 0; ctr < 4; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 <<= 13;
    tmp0 += ((INT32)1) << (13 - 2 - 1);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp1 = ((z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((z1) * (((INT32)4433)));
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp12 = tmp0 + tmp2;
    tmp13 = tmp0 - tmp2;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
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
    wsptr[8 * 0] = (int)((tmp20 + tmp0) >> (13 - 2));
    wsptr[8 * 15] = (int)((tmp20 - tmp0) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp21 + tmp1) >> (13 - 2));
    wsptr[8 * 14] = (int)((tmp21 - tmp1) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp22 + tmp2) >> (13 - 2));
    wsptr[8 * 13] = (int)((tmp22 - tmp2) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp23 + tmp3) >> (13 - 2));
    wsptr[8 * 12] = (int)((tmp23 - tmp3) >> (13 - 2));
}
}
