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
for (ctr = 16; ctr > 0; ctr -= 2) {
    int dcval_high, dcval_low;
    JCOEFPTR inptr_backup = inptr;
    ISLOW_MULT_TYPE *quantptr_backup = quantptr;
    int *wsptr_backup = wsptr;

    if ((inptr[8 * 0] | inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | 
         inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
        dcval_low = 0;
    } else {
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp2 = z1 + ((z3) * (-((INT32)15137)));
        tmp3 = z1 + ((z2) * (((INT32)6270)));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        tmp0 = (z2 + z3) << 13;
        tmp1 = (z2 - z3) << 13;
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
        tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
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
        dcval_low = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    }

    inptr++;
    quantptr++;
    wsptr++;

    if ((inptr[8 * 0] | inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | 
         inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
        dcval_high = 0;
    } else {
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp2 = z1 + ((z3) * (-((INT32)15137)));
        tmp3 = z1 + ((z2) * (((INT32)6270)));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        tmp0 = (z2 + z3) << 13;
        tmp1 = (z2 - z3) << 13;
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
        tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
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
        dcval_high = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    }

    inptr = inptr_backup;
    quantptr = quantptr_backup;
    wsptr = wsptr_backup;

    if (dcval_low == 0 && dcval_high == 0) {
        for (int i = 0; i < 8; i++) {
            wsptr[i] = 0;
            wsptr[8 + i] = 0;
        }
    } else {
        wsptr[8 * 0] = (int)(((tmp10 + tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 7] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 1] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 6] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 2] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 5] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 3] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 4] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));

        wsptr[8 + 8 * 0] = (int)(((tmp10 + tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 7] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 1] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 6] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 2] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 5] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 3] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 + 8 * 4] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    }

    inptr += 2;
    quantptr += 2;
    wsptr += 16;
}
}
