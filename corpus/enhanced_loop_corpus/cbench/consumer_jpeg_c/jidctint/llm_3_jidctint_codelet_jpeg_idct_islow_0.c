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
const int indices[8] = {0, 8, 16, 24, 32, 40, 48, 56};
for (ctr = 8; ctr > 0; ctr--) {
    int non_zero_found = 0;
    for (int i = 1; i < 8; i++) {
        if (inptr[indices[i]] != 0) {
            non_zero_found = 1;
            break;
        }
    }

    if (!non_zero_found) {
        int dcval = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]])) << 2;
        for (int i = 0; i < 8; i++) {
            wsptr[i] = dcval;
        }
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    z2 = (((ISLOW_MULT_TYPE)(inptr[indices[2]])) * (quantptr[indices[2]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[indices[6]])) * (quantptr[indices[6]]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp2 = z1 + ((z3) * (-((INT32)15137)));
    tmp3 = z1 + ((z2) * (((INT32)6270)));

    z2 = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[indices[4]])) * (quantptr[indices[4]]));
    tmp0 = (z2 + z3) << 13;
    tmp1 = (z2 - z3) << 13;

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
    wsptr[7] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[1] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[6] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[2] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[5] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[3] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[4] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));

    inptr++;
    quantptr++;
    wsptr++;
}
}
