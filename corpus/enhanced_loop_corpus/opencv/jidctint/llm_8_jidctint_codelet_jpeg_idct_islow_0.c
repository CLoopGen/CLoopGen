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
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 4; ctr > 0; ctr--) {
    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << (1)));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        inptr += 2;
        quantptr += 2;
        wsptr += 2;
        continue;
    }
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    z1 = ((z2 + z3) * (((JLONG)4433)));
    tmp2 = z1 + ((z3) * (-((JLONG)15137)));
    tmp3 = z1 + ((z2) * (((JLONG)6270)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp0 = ((JLONG)((unsigned long)(z2 + z3) << (13)));
    tmp1 = ((JLONG)((unsigned long)(z2 - z3) << (13)));
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
    z5 = ((z3 + z4) * (((JLONG)9633)));
    tmp0 = ((tmp0) * (((JLONG)2446)));
    tmp1 = ((tmp1) * (((JLONG)16819)));
    tmp2 = ((tmp2) * (((JLONG)25172)));
    tmp3 = ((tmp3) * (((JLONG)12299)));
    z1 = ((z1) * (-((JLONG)7373)));
    z2 = ((z2) * (-((JLONG)20995)));
    z3 = ((z3) * (-((JLONG)16069)));
    z4 = ((z4) * (-((JLONG)3196)));
    z3 += z5;
    z4 += z5;
    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;
    wsptr[8 * 0] = (int)(((tmp10 + tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 7] = (int)(((tmp10 - tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 1] = (int)(((tmp11 + tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 6] = (int)(((tmp11 - tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 2] = (int)(((tmp12 + tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 5] = (int)(((tmp12 - tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 3] = (int)(((tmp13 + tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 4] = (int)(((tmp13 - tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    inptr += 2;
    quantptr += 2;
    wsptr += 2;
}

}
