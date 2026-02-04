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
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: simplified arithmetic, fewer multiplications, lower trip count
for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
    // Simplified version: remove high-precision constants and reduce operations
    // Approximate multiplications using shifts or simpler factors

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 <<= 13;
    z1 += (1 << (13 - 3));  // Reduced bias

    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

    // Replace complex multiplies with approximate values using powers of two
    tmp10 = z4 >> 1;  // ~0.5 instead of 0.437
    tmp11 = z4 + (z4 >> 3);  // ~1.125 instead of 1.144
    tmp12 = z1 - tmp10;
    tmp13 = z1 + tmp11;
    z1 -= (tmp11 - tmp10) << 1;

    z4 = z2 - z3;
    z3 += z2;

    tmp10 = z3 + (z3 >> 1);  // ~1.5 instead of 1.338
    tmp11 = z4 >> 4;         // ~0.0625 instead of 0.0457
    z2 = z2 + (z2 >> 1);     // ~1.5 instead of 1.44

    tmp20 = tmp13 + tmp10 + tmp11;
    tmp23 = tmp12 - tmp10 + tmp11 + z2;

    tmp10 = z3 >> 1;         // ~0.5 instead of 0.547
    tmp11 = z4 >> 2;         // ~0.25 instead of 0.399
    tmp25 = tmp13 - tmp10 - tmp11;
    tmp26 = tmp12 + tmp10 - tmp11 - z2;

    tmp10 = z3 - (z3 >> 3);  // ~0.875 instead of 0.790
    tmp11 = z4 >> 2;         // ~0.25 instead of 0.353
    tmp21 = tmp12 + tmp10 + tmp11;
    tmp24 = tmp13 - tmp10 + tmp11;

    tmp11 += tmp11;
    tmp22 = z1 + tmp11;
    tmp27 = z1 - tmp11 - tmp11;

    // Skip second half computations (odd indices) for reduced intensity
    // Simulate final outputs with scaled versions of first half

    wsptr[8 * 0] = (int)(tmp20 >> (13 - 2));
    wsptr[8 * 14] = (int)((tmp20 - (tmp20 >> 3)) >> (13 - 2));
    wsptr[8 * 1] = (int)(tmp21 >> (13 - 2));
    wsptr[8 * 13] = (int)((tmp21 - (tmp21 >> 3)) >> (13 - 2));
    wsptr[8 * 2] = (int)(tmp22 >> (13 - 2));
    wsptr[8 * 12] = (int)((tmp22 - (tmp22 >> 3)) >> (13 - 2));
    wsptr[8 * 3] = (int)(tmp23 >> (13 - 2));
    wsptr[8 * 11] = (int)((tmp23 - (tmp23 >> 3)) >> (13 - 2));
    wsptr[8 * 4] = (int)(tmp24 >> (13 - 2));
    wsptr[8 * 10] = (int)((tmp24 - (tmp24 >> 3)) >> (13 - 2));
    wsptr[8 * 5] = (int)(tmp25 >> (13 - 2));
    wsptr[8 * 9] = (int)((tmp25 - (tmp25 >> 3)) >> (13 - 2));
    wsptr[8 * 6] = (int)(tmp26 >> (13 - 2));
    wsptr[8 * 8] = (int)((tmp26 - (tmp26 >> 3)) >> (13 - 2));
    wsptr[8 * 7] = (int)(tmp27 >> (13 - 2));
}
}
