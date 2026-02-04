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



void loop() {
    // Loop-carried dependency introduced via carry-over variable
    INT32 carry_tmp10 = 0, carry_tmp13 = 0;

    for (ctr = 8; ctr > 0; ctr--) {
        // Create loop-carried WAW and RAW dependency using previous iteration's result
        tmp10 = (ctr == 8) ? 0 : carry_tmp10;
        tmp13 = (ctr == 8) ? 0 : carry_tmp13;

        if ((inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
            wsptr[8 * 0] = dcval + tmp10; // Introduce dependency on tmp10 from prior iteration
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval + tmp13; // Introduce dependency on tmp13
            inptr++;
            quantptr++;
            wsptr++;
            // Preserve state for next iteration
            carry_tmp10 = dcval;
            carry_tmp13 = dcval;
            continue;
        }

        // Reorder operations to introduce artificial dependencies
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2])) + tmp10; // RAW: depends on prior loop's tmp10
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6])) + tmp13;
        z1 = ((z2 + z3) * (((INT32)4433)));

        tmp2 = z1 + ((z3) * (-((INT32)15137)));
        tmp3 = z1 + ((z2) * (((INT32)6270)));

        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));

        // Modify base values using results from previous iteration to strengthen loop-carried dependency
        tmp0 = (z2 + z3 + carry_tmp10) << 13;
        tmp1 = (z2 - z3 + carry_tmp13) << 13;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;

        // Staggered computation order to enforce specific data flow
        tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = ((z3 + z4) * (((INT32)9633)));

        // Deepen arithmetic chain with cumulative effects
        tmp0 = ((tmp0) * (((INT32)2446))) + z1;
        tmp1 = ((tmp1) * (((INT32)16819))) + z2;
        tmp2 = ((tmp2) * (((INT32)25172))) + z3;
        tmp3 = ((tmp3) * (((INT32)12299))) + z4;

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

        wsptr[8 * 0] = (int)(((tmp10 + tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 7] = (int)(((tmp10 - tmp3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 1] = (int)(((tmp11 + tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 6] = (int)(((tmp11 - tmp2) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 2] = (int)(((tmp12 + tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 5] = (int)(((tmp12 - tmp1) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 3] = (int)(((tmp13 + tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        wsptr[8 * 4] = (int)(((tmp13 - tmp0) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));

        // Save state for next iteration — creates strong loop-carried dependency
        carry_tmp10 = tmp10;
        carry_tmp13 = tmp13;

        inptr++;
        quantptr++;
        wsptr++;
    }
}
