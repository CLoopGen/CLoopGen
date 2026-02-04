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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 16; ctr > 0; ctr -= 2) {
    for (int unroll = 0; unroll < 2; unroll++) {
        if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 &&
            inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval;
        } else {
            z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
            z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
            z2 <<= 14;
            z3 <<= 14;
            z2 += ((INT32)1) << (14 - 2 - 1);
            tmp0 = z2 + z3;
            tmp1 = z2 - z3;
            z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
            z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
            z1 = ((z2 + z3) * (((INT32)4433)));
            tmp2 = z1 + ((z2) * (((INT32)6270)));
            tmp3 = z1 - ((z3) * (((INT32)15137)));
            tmp10 = tmp0 + tmp2;
            tmp13 = tmp0 - tmp2;
            tmp11 = tmp1 + tmp3;
            tmp12 = tmp1 - tmp3;
            tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
            tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
            tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
            tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
            z2 = tmp0 + tmp2;
            z3 = tmp1 + tmp3;
            z1 = ((z2 + z3) * (((INT32)9633)));
            z2 = ((z2) * (-((INT32)16069)));
            z3 = ((z3) * (-((INT32)3196)));
            z2 += z1;
            z3 += z1;
            z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
            tmp0 = ((tmp0) * (((INT32)2446)));
            tmp3 = ((tmp3) * (((INT32)12299)));
            tmp0 += z1 + z2;
            tmp3 += z1 + z3;
            z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
            tmp1 = ((tmp1) * (((INT32)16819)));
            tmp2 = ((tmp2) * (((INT32)25172)));
            tmp1 += z1 + z3;
            tmp2 += z1 + z2;
            wsptr[8 * 0] = (int)((tmp10 + tmp3) >> (14 - 2));
            wsptr[8 * 7] = (int)((tmp10 - tmp3) >> (14 - 2));
            wsptr[8 * 1] = (int)((tmp11 + tmp2) >> (14 - 2));
            wsptr[8 * 6] = (int)((tmp11 - tmp2) >> (14 - 2));
            wsptr[8 * 2] = (int)((tmp12 + tmp1) >> (14 - 2));
            wsptr[8 * 5] = (int)((tmp12 - tmp1) >> (14 - 2));
            wsptr[8 * 3] = (int)((tmp13 + tmp0) >> (14 - 2));
            wsptr[8 * 4] = (int)((tmp13 - tmp0) >> (14 - 2));
        }
        inptr++;
        quantptr++;
        wsptr++;
    }
}

}
