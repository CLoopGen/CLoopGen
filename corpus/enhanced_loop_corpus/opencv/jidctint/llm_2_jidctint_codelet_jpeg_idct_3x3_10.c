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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements with stride 8, reorganize data access to use consecutive indices.
    // Assume input data has been pre-reorganized so that inptr[i], quantptr[i] correspond to original [8*i].
    for (ctr = 0; ctr < 3; ctr++, inptr++, quantptr++, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
        tmp0 <<= 13;
        tmp0 += ((INT32)1) << (13 - 2 - 1);
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[2])) * (quantptr[2]));
        tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp0 + tmp12;
        tmp2 = tmp0 - tmp12 - tmp12;
        tmp12 = (((ISLOW_MULT_TYPE)(inptr[1])) * (quantptr[1]));
        tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        wsptr[0] = (int)((tmp10 + tmp0) >> (13 - 2));
        wsptr[2] = (int)((tmp10 - tmp0) >> (13 - 2));
        wsptr[1] = (int)((tmp2) >> (13 - 2));
    }
}
