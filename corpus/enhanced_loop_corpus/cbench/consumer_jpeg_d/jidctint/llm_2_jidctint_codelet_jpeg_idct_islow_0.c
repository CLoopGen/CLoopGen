#include <stdio.h>

#include <inttypes.h>

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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    if ((inptr[0] | inptr[16] | inptr[24] | inptr[32] | inptr[40] | inptr[48] | inptr[56]) == 0) {
        int dcval = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0])) << 2;
        wsptr[0] = dcval;
        wsptr[8] = dcval;
        wsptr[16] = dcval;
        wsptr[24] = dcval;
        wsptr[32] = dcval;
        wsptr[40] = dcval;
        wsptr[48] = dcval;
        wsptr[56] = dcval;
        inptr += 8;
        quantptr += 8;
        wsptr += 8;
        continue;
    }
    z2 = (((ISLOW_MULT_TYPE)(inptr[16])) * (quantptr[16]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[48])) * (quantptr[48]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp2 = z1 + ((z3) * (-((INT32)15137)));
    tmp3 = z1 + ((z2) * (((INT32)6270)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[32])) * (quantptr[32]));
    tmp0 = (z2 + z3) << 13;
    tmp1 = (z2 - z3) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[56])) * (quantptr[56]));
    tmp1 = (((ISLOW_MULT_TYPE)(inptr[40])) * (quantptr[40]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[24])) * (quantptr[24]));
    tmp3 = (((ISLOW_MULT_TYPE)(inptr[8])) * (quantptr[8]));
    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = ((z3 + z4) * (((INT32)9633)));
    tmp0 = ((tmp0) * (((INT32)2446)));
    tmp1 = ((tmp1) * (((INT32)16819)));
    tmp2 = ((tmp2) * (((INT32)25172)));
    tmp3 = ((tmp3) * (((INT32)12299)));
    z1 = ((z1) * (-((INT32)7373)));
    z2 = ((z2) * (-((INT32)20995)));
    z3 = ((z3) * (-((INT32)16069)));
    z4 = ((z4) * (-((INT32)3196)));
    z3 += z5;
    z4 += z5;
    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;
    wsptr[0] = (int)(((tmp10 + tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[56] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[48] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[16] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[40] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[24] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[32] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    inptr += 8;
    quantptr += 8;
    wsptr += 8;
}
}
