#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with introduced loop-carried dependence via cumulative sum in tmp0
INT32 accumulator = 0;
for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
    // Make tmp0 dependent on previous iteration's result (introduce loop-carried RAW/WAW)
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) + accumulator;
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp10 = (tmp0 + tmp2) << 2;
    tmp12 = (tmp0 - tmp2) << 2;

    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z1 = ((z2 + z3) * ((INT32)4433)) + (((INT32)1) << (13 - 2 - 1));

    // Modify evaluation order: compute final outputs before updating state
    INT32 out0 = ((z1 + (z2 * (INT32)6270)) >> (13 - 2));
    INT32 out2 = ((z1 - (z3 * (INT32)15137)) >> (13 - 2));

    wsptr[4 * 0] = (int)(tmp10 + out0);
    wsptr[4 * 3] = (int)(tmp10 - out0);
    wsptr[4 * 1] = (int)(tmp12 + out2);
    wsptr[4 * 2] = (int)(tmp12 - out2);

    // Update accumulator for next iteration (creates loop-carried dependency)
    accumulator = tmp0 >> 1; // artificial carry-over to create dependency across iterations
}
}
