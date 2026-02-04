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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reduced computational complexity with simplified inner structure
    // Trip count reduced to 4, and multiple operations merged or removed.
    // Only essential data paths preserved; some multiplies replaced with shifts.

    for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
        // Simplified version: remove half of the coefficient accesses
        // Use only even indices (0, 2, 4, 6) and skip odd ones
        tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp10 <<= 13;
        tmp10 += ((INT32)1) << (13 - 2 - 1);

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

        // Approximate using fixed-point constants as integer literals (precomputed)
        const INT32 C1 = (INT32)(2.5466401319999998 * (1 << 13) + 0.5); // ~20860
        const INT32 C2 = (INT32)(1.414213562 * (1 << 13) + 0.5);         // ~11585

        tmp20 = (z2 - z3) * C1;
        z4 = z1 + z3 - z2;
        tmp25 = tmp10 + (z4 * 11000);  // approx 1.3569 scaled
        tmp21 = tmp20 + tmp25 - (z2 * 14920); // approx 1.8218 scaled
        tmp20 += tmp25 + (z3 * 17320); // approx 2.1158 scaled
        tmp24 = (z1 + z3) * (-9460);   // approx -1.1557 scaled
        tmp24 += tmp25;
        tmp22 = tmp24 - (z3 * 6460);   // approx 0.7887 scaled
        tmp24 += (z2 * 15920) - (z1 * 11380); // approx 1.9444 and 1.3909
        tmp25 = tmp10 - (z4 * C2);

        // Skip all odd-indexed input processing (1,3,5,7)
        // Use dummy values for tmp10–tmp14
        tmp10 = 0; tmp11 = 0; tmp12 = 0; tmp13 = 0; tmp14 = 0;

        // Output every other position, reduce writes
        wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsptr[8 * 5] = (int)(tmp25 >> (13 - 2));
        wsptr[8 * 10] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsptr[8 * 8] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 2));
        wsptr[8 * 6] = (int)((tmp24 - tmp14) >> (13 - 2));

        // Add minimal extra operation to preserve basic flow
        tmp10 += tmp20 ^ tmp25;
    }
}
