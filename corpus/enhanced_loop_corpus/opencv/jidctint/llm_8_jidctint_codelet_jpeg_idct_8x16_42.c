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
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    z3 = z1 - z2;
    z3 = ((z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
    tmp0 = z3 + ((z2) * (((INT32)20995)));
    tmp1 = ((z1) * (((INT32)7373)));
    tmp20 = tmp10 + tmp0;
    tmp27 = tmp10 - tmp0;
    tmp21 = tmp11 + tmp1;
    tmp26 = tmp11 - tmp1;
    wsptr[8 * 0] = (int)((tmp20) >> (13 - 2));
    wsptr[8 * 15] = (int)((tmp27) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp21) >> (13 - 2));
    wsptr[8 * 14] = (int)((tmp26) >> (13 - 2));
}
}
