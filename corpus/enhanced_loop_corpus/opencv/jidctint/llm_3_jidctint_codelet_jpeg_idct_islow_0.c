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



void loop() {
    int indices[8] = {0, 8, 16, 24, 32, 40, 48, 56};
    for (ctr = 8; ctr > 0; ctr--) {
        if (inptr[indices[1]] == 0 && inptr[indices[2]] == 0 && inptr[indices[3]] == 0 &&
            inptr[indices[4]] == 0 && inptr[indices[5]] == 0 && inptr[indices[6]] == 0 &&
            inptr[indices[7]] == 0) {
            int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]))) << (1)));
            for (int i = 0; i < 8; i++) {
                wsptr[indices[i] >> 3] = dcval;
            }
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }
        z2 = (((ISLOW_MULT_TYPE)(inptr[indices[2]])) * (quantptr[indices[2]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[indices[6]])) * (quantptr[indices[6]]));
        z1 = ((z2 + z3) * (((JLONG)4433)));
        tmp2 = z1 + ((z3) * (-((JLONG)15137)));
        tmp3 = z1 + ((z2) * (((JLONG)6270)));
        z2 = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[indices[4]])) * (quantptr[indices[4]]));
        tmp0 = ((JLONG)((unsigned long)(z2 + z3) << (13)));
        tmp1 = ((JLONG)((unsigned long)(z2 - z3) << (13)));
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[indices[7]])) * (quantptr[indices[7]]));
        tmp1 = (((ISLOW_MULT_TYPE)(inptr[indices[5]])) * (quantptr[indices[5]]));
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[indices[3]])) * (quantptr[indices[3]]));
        tmp3 = (((ISLOW_MULT_TYPE)(inptr[indices[1]])) * (quantptr[indices[1]]));
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
        wsptr[0] = (int)(((tmp10 + tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[7] = (int)(((tmp10 - tmp3) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[1] = (int)(((tmp11 + tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[6] = (int)(((tmp11 - tmp2) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[2] = (int)(((tmp12 + tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[5] = (int)(((tmp12 - tmp1) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[3] = (int)(((tmp13 + tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        wsptr[4] = (int)(((tmp13 - tmp0) + (((JLONG)1) << ((13 - 1) - 1))) >> (13 - 1));
        inptr++;
        quantptr++;
        wsptr++;
    }
}
