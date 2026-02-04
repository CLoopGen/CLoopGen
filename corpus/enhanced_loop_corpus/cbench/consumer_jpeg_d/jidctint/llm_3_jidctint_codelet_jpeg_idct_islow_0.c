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
int indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
for (ctr = 8; ctr > 0; ctr--) {
    int idx0 = indices[0] * 8, idx1 = indices[1] * 8, idx2 = indices[2] * 8,
        idx3 = indices[3] * 8, idx4 = indices[4] * 8, idx5 = indices[5] * 8,
        idx6 = indices[6] * 8, idx7 = indices[7] * 8;

    if ((inptr[idx1] | inptr[idx2] | inptr[idx3] | inptr[idx4] | inptr[idx5] | inptr[idx6] | inptr[idx7]) == 0) {
        int dcval = (((ISLOW_MULT_TYPE)(inptr[idx0])) * (quantptr[idx0])) << 2;
        wsptr[idx0] = dcval;
        wsptr[idx1] = dcval;
        wsptr[idx2] = dcval;
        wsptr[idx3] = dcval;
        wsptr[idx4] = dcval;
        wsptr[idx5] = dcval;
        wsptr[idx6] = dcval;
        wsptr[idx7] = dcval;
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }
    z2 = (((ISLOW_MULT_TYPE)(inptr[idx2])) * (quantptr[idx2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[idx6])) * (quantptr[idx6]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp2 = z1 + ((z3) * (-((INT32)15137)));
    tmp3 = z1 + ((z2) * (((INT32)6270)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[idx0])) * (quantptr[idx0]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[idx4])) * (quantptr[idx4]));
    tmp0 = (z2 + z3) << 13;
    tmp1 = (z2 - z3) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[idx7])) * (quantptr[idx7]));
    tmp1 = (((ISLOW_MULT_TYPE)(inptr[idx5])) * (quantptr[idx5]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[idx3])) * (quantptr[idx3]));
    tmp3 = (((ISLOW_MULT_TYPE)(inptr[idx1])) * (quantptr[idx1]));
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
    wsptr[idx0] = (int)(((tmp10 + tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx7] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx1] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx6] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx2] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx5] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx3] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[idx4] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    inptr++;
    quantptr++;
    wsptr++;
}
}
