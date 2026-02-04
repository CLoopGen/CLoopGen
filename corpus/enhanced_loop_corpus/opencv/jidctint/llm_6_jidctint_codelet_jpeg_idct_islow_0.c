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
for (ctr = 8; ctr > 0; ctr--) {
    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << (1)));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        wsptr[8 * 4] = dcval;
        wsptr[8 * 5] = dcval;
        wsptr[8 * 6] = dcval;
        wsptr[8 * 7] = dcval;
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }
    JLONG temp_vals[8];
    temp_vals[0] = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    temp_vals[1] = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    temp_vals[2] = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    temp_vals[3] = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    temp_vals[4] = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    temp_vals[5] = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    temp_vals[6] = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    temp_vals[7] = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    z2 = temp_vals[2];
    z3 = temp_vals[6];
    z1 = ((z2 + z3) * (((JLONG)4433)));
    tmp2 = z1 + ((z3) * (-((JLONG)15137)));
    tmp3 = z1 + ((z2) * (((JLONG)6270)));

    tmp0 = ((JLONG)((unsigned long)(temp_vals[0] + temp_vals[4]) << (13)));
    tmp1 = ((JLONG)((unsigned long)(temp_vals[0] - temp_vals[4]) << (13)));
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    z1 = temp_vals[7] + temp_vals[1];
    z2 = temp_vals[5] + temp_vals[3];
    z3 = temp_vals[7] + temp_vals[3];
    z4 = temp_vals[5] + temp_vals[1];
    z5 = ((z3 + z4) * (((JLONG)9633)));

    JLONG t0 = ((temp_vals[7]) * (((JLONG)2446)));
    JLONG t1 = ((temp_vals[5]) * (((JLONG)16819)));
    JLONG t2 = ((temp_vals[3]) * (((JLONG)25172)));
    JLONG t3 = ((temp_vals[1]) * (((JLONG)12299)));

    z1 = ((z1) * (-((JLONG)7373)));
    z2 = ((z2) * (-((JLONG)20995)));
    z3 = ((z3) * (-((JLONG)16069)));
    z4 = ((z4) * (-((JLONG)3196)));

    z3 += z5;
    z4 += z5;

    tmp0 = t0 + z1 + z3;
    tmp1 = t1 + z2 + z4;
    tmp2 = t2 + z2 + z3;
    tmp3 = t3 + z1 + z4;

    wsptr[8 * 0] = (int)(((tmp10 + tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 7] = (int)(((tmp10 - tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 1] = (int)(((tmp11 + tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 6] = (int)(((tmp11 - tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 2] = (int)(((tmp12 + tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 5] = (int)(((tmp12 - tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 3] = (int)(((tmp13 + tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
    wsptr[8 * 4] = (int)(((tmp13 - tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));

    inptr++;
    quantptr++;
    wsptr++;
}
}
