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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++, inptr += 2, quantptr += 2, wsptr += 4) {
    // Increased computational intensity: two stages processed with additional arithmetic
    INT32 tmp0_0, tmp0_1, tmp2_0, tmp2_1, tmp10_0, tmp10_1, tmp12_0, tmp12_1;

    // First element (original index)
    tmp0_0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0_0 <<= 13;
    tmp0_0 += ((INT32)1) << (13 - 2 - 1);
    tmp2_0 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp12_0 = ((tmp2_0) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10_0 = tmp0_0 + tmp12_0;
    tmp2_0 = tmp0_0 - tmp12_0 - tmp12_0;
    tmp12_0 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0_0 = ((tmp12_0) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Second element (next coefficient, offset by 1)
    tmp0_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0 + 1])) * (quantptr[8 * 0 + 1]));
    tmp0_1 <<= 13;
    tmp0_1 += ((INT32)1) << (13 - 2 - 1);
    tmp2_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2 + 1])) * (quantptr[8 * 2 + 1]));
    tmp12_1 = ((tmp2_1) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10_1 = tmp0_1 + tmp12_1;
    tmp2_1 = tmp0_1 - tmp12_1 - tmp12_1;
    tmp12_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1 + 1])) * (quantptr[8 * 1 + 1]));
    tmp0_1 = ((tmp12_1) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Combined outputs with cross-terms to increase complexity
    wsptr[6 * 0]     = (int)(((tmp10_0 + tmp0_0) + (tmp10_1 + tmp0_1)) >> (13 - 2));
    wsptr[6 * 0 + 1] = (int)(((tmp10_0 + tmp0_0) - (tmp10_1 + tmp0_1)) >> (13 - 2));
    wsptr[6 * 2]     = (int)(((tmp10_0 - tmp0_0) + (tmp10_1 - tmp0_1)) >> (13 - 2));
    wsptr[6 * 2 + 1] = (int)(((tmp10_0 - tmp0_0) - (tmp10_1 - tmp0_1)) >> (13 - 2));
    wsptr[6 * 1]     = (int)((tmp2_0 + tmp2_1) >> (13 - 2));
    wsptr[6 * 1 + 1] = (int)((tmp2_0 - tmp2_1) >> (13 - 2));
    wsptr[6 * 1 + 2] = (int)((tmp2_0 + (tmp2_1 >> 1)) >> (13 - 2)); // Extra derived term
    wsptr[6 * 1 + 3] = (int)((tmp2_1 + (tmp2_0 >> 1)) >> (13 - 2)); // Extra derived term
}
}
