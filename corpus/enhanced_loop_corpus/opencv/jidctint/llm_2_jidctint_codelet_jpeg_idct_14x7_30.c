#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing every 8th element (strided), we reorganize data to use consecutive indices.
    // Assume input data has been pre-transposed or reordered so that [0], [2], [4], [6], etc., are now adjacent.
    
    JCOEFPTR inptr_local = inptr;
    ISLOW_MULT_TYPE *quantptr_local = quantptr;
    int *wsptr_local = wsptr;

    for (ctr = 0; ctr < 8; ctr++, inptr_local++, quantptr_local++, wsptr_local++) {
        // Reordered coefficients: now stored consecutively: index 0,1,2,3 correspond to original 0,2,4,6
        tmp23 = (((ISLOW_MULT_TYPE)(inptr_local[0])) * (quantptr_local[0]));
        tmp23 <<= 13;
        tmp23 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr_local[1])) * (quantptr_local[1]));
        z2 = (((ISLOW_MULT_TYPE)(inptr_local[2])) * (quantptr_local[2]));
        z3 = (((ISLOW_MULT_TYPE)(inptr_local[3])) * (quantptr_local[3]));

        tmp20 = ((z2 - z3) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 = ((z1 - z2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp22 + tmp23 - ((z2) * (((INT32)((1.841218003) * (((INT32)1) << 13) + 0.5))));

        tmp10 = z1 + z3;
        z2 -= tmp10;
        tmp10 = ((tmp10) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + tmp23;
        tmp20 += tmp10 - ((z3) * (((INT32)((0.077722535999999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 += tmp10 - ((z1) * (((INT32)((2.4706022490000001) * (((INT32)1) << 13) + 0.5))));
        tmp23 += ((z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

        // Next set: odd indices now also accessed consecutively
        z1 = (((ISLOW_MULT_TYPE)(inptr_local[4])) * (quantptr_local[4])); // was 8*1 -> now offset 4
        z2 = (((ISLOW_MULT_TYPE)(inptr_local[5])) * (quantptr_local[5])); // was 8*3 -> now 5
        z3 = (((ISLOW_MULT_TYPE)(inptr_local[6])) * (quantptr_local[6])); // was 8*5 -> now 6

        tmp11 = ((z1 + z2) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 - tmp12;
        tmp11 += tmp12;
        tmp12 = ((z2 + z3) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp12;
        z2 = ((z1 + z3) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp12 += z2 + ((z3) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));

        // Store results with consecutive output indexing
        wsptr_local[0] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsptr_local[6] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsptr_local[1] = (int)((tmp21 + tmp11) >> (13 - 2));
        wsptr_local[5] = (int)((tmp21 - tmp11) >> (13 - 2));
        wsptr_local[2] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsptr_local[4] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsptr_local[3] = (int)((tmp23) >> (13 - 2));
    }
}
