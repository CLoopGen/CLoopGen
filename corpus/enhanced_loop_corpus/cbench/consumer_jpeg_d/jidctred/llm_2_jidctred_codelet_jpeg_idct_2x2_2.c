#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern INT32 z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Reordered Array Layout Simulation
    // Instead of strided access (8 * i), we assume input data has been pre-reorganized 
    // into consecutive arrays for DC and AC coefficients to enable linear access.

    int offset = 0;
    for (ctr = 8; ctr > 0; ctr--, offset++) {
        if (ctr == 6 || ctr == 4 || ctr == 2)
            continue;

        // Simulate consecutive storage: in_consec[0..7] = [in[0], in[8], in[16], ..., in[56]]
        // Same for quantptr. This removes multiplication by 8 in indexing.
        if ((inptr[offset + 1] | inptr[offset + 3] | inptr[offset + 5] | inptr[offset + 7]) == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(inptr[offset])) * (quantptr[offset])) << 2;
            wsptr[offset] = dcval;
            wsptr[offset + 1] = dcval;
            offset += 7; // Skip remaining AC terms for this group (simulating block jump)
            continue;
        }

        z1 = (((ISLOW_MULT_TYPE)(inptr[offset])) * (quantptr[offset]));
        tmp10 = z1 << (13 + 2);
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 7])) * (quantptr[offset + 7]));
        tmp0 = ((z1) * (-((INT32)5906)));
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 5])) * (quantptr[offset + 5]));
        tmp0 += ((z1) * (((INT32)6967)));
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 3])) * (quantptr[offset + 3]));
        tmp0 += ((z1) * (-((INT32)10426)));
        z1 = (((ISLOW_MULT_TYPE)(inptr[offset + 1])) * (quantptr[offset + 1]));
        tmp0 += ((z1) * (((INT32)29692)));

        int shift = 13 - 2 + 2;
        wsptr[offset]     = (int)(((tmp10 + tmp0) + (((INT32)1) << (shift - 1))) >> shift);
        wsptr[offset + 1] = (int)(((tmp10 - tmp0) + (((INT32)1) << (shift - 1))) >> shift);
        
        offset += 7; // Advance past the full 8-element block
    }
}
