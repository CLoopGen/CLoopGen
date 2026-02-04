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
// Eliminate loop-carried dependencies and reduce data hazards via privatization
#pragma loop no_vector // Indicate intent to prevent vectorization due to transformations
for (ctr = 8; ctr > 0; ctr--) {
    INT32 private_tmp0, private_tmp1, private_tmp2, private_tmp3;
    INT32 private_tmp10, private_tmp11, private_tmp12, private_tmp13;
    INT32 private_z1, private_z2, private_z3, private_z4, private_z5;
    int dcval;

    if ((inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
        dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
        for (int k = 0; k < 8; k++) {
            wsptr[8 * k] = dcval; // Fully unrolled store with no inter-element dependency
        }
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    private_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    private_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    private_z1 = ((private_z2 + private_z3) * (((INT32)4433)));
    private_tmp2 = private_z1 + ((private_z3) * (-((INT32)15137)));
    private_tmp3 = private_z1 + ((private_z2) * (((INT32)6270)));
    private_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    private_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    private_tmp0 = (private_z2 + private_z3) << 13;
    private_tmp1 = (private_z2 - private_z3) << 13;
    private_tmp10 = private_tmp0 + private_tmp3;
    private_tmp13 = private_tmp0 - private_tmp3;
    private_tmp11 = private_tmp1 + private_tmp2;
    private_tmp12 = private_tmp1 - private_tmp2;
    private_tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    private_tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    private_tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    private_tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    private_z1 = private_tmp0 + private_tmp3;
    private_z2 = private_tmp1 + private_tmp2;
    private_z3 = private_tmp0 + private_tmp2;
    private_z4 = private_tmp1 + private_tmp3;
    private_z5 = ((private_z3 + private_z4) * (((INT32)9633)));
    private_tmp0 = ((private_tmp0) * (((INT32)2446)));
    private_tmp1 = ((private_tmp1) * (((INT32)16819)));
    private_tmp2 = ((private_tmp2) * (((INT32)25172)));
    private_tmp3 = ((private_tmp3) * (((INT32)12299)));
    private_z1 = ((private_z1) * (-((INT32)7373)));
    private_z2 = ((private_z2) * (-((INT32)20995)));
    private_z3 = ((private_z3) * (-((INT32)16069)));
    private_z4 = ((private_z4) * (-((INT32)3196)));
    private_z3 += private_z5;
    private_z4 += private_z5;
    private_tmp0 += private_z1 + private_z3;
    private_tmp1 += private_z2 + private_z4;
    private_tmp2 += private_z2 + private_z3;
    private_tmp3 += private_z1 + private_z4;

    // Store results using computed temporaries — no reuse of shared variables
    wsptr[8 * 0] = (int)(((private_tmp10 + private_tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 7] = (int)(((private_tmp10 - private_tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 1] = (int)(((private_tmp11 + private_tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 6] = (int)(((private_tmp11 - private_tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 2] = (int)(((private_tmp12 + private_tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 5] = (int)(((private_tmp12 - private_tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 3] = (int)(((private_tmp13 + private_tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
    wsptr[8 * 4] = (int)(((private_tmp13 - private_tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));

    // No cross-iteration dependencies; all operations use local privates
    inptr++;
    quantptr++;
    wsptr++;
}
}
