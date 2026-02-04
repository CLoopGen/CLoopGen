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
// Variant with reduced loop-carried and modified RAW/WAR dependencies using interleaved computation
for (ctr = 0; ctr < 6; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    // Process two elements per iteration to change data flow pattern and reduce loop iterations' dependency chain
    INT32 tmp0_1, tmp2_1, tmp10_1, tmp12_1;
    INT32 tmp0_2, tmp2_2, tmp10_2, tmp12_2;

    // First element (original index)
    tmp0_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0_1 <<= 13;
    tmp0_1 += ((INT32)1) << (13 - 2 - 1);
    tmp2_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp12_1 = ((tmp2_1) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10_1 = tmp0_1 + tmp12_1;
    tmp2_1 = tmp0_1 - tmp12_1 - tmp12_1;
    tmp12_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0_1 = ((tmp12_1) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Second element (next index), no dependency on first result — enables parallelism
    tmp0_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1])); // Reuse offset differently
    tmp0_2 <<= 13;
    tmp0_2 += ((INT32)1) << (13 - 2 - 1);
    tmp2_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp12_2 = ((tmp2_2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10_2 = tmp0_2 + tmp12_2;
    tmp2_2 = tmp0_2 - tmp12_2 - tmp12_2;
    tmp12_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp0_2 = ((tmp12_2) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Write results in reverse order to alter WAR dependencies
    wsptr[6 * 2] = (int)((tmp10_1 + tmp0_1) >> (13 - 2)); // Original wsptr[0] equivalent
    wsptr[6 * 1] = (int)((tmp10_1 - tmp0_1) >> (13 - 2));
    wsptr[6 * 0] = (int)(tmp2_1 >> (13 - 2));

    wsptr[6 * 5] = (int)((tmp10_2 + tmp0_2) >> (13 - 2));
    wsptr[6 * 4] = (int)((tmp10_2 - tmp0_2) >> (13 - 2));
    wsptr[6 * 3] = (int)(tmp2_2 >> (13 - 2));
}
}
