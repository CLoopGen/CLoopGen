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
    // Variant 2: Strided Memory Access with Increased Stride
    // Modify access pattern to use a larger stride (e.g., 16 instead of 8) to simulate block-based or padded memory layout.
    for (ctr = 0; ctr < 3; ctr++, inptr += 2, quantptr += 2, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[0 * 16])) * (quantptr[0 * 16]));
        tmp0 <<= 13;
        tmp0 += ((INT32)1) << (13 - 2 - 1);
        tmp2 = (((ISLOW_MULT_TYPE)(inptr[2 * 16])) * (quantptr[2 * 16]));
        tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp0 + tmp12;
        tmp2 = tmp0 - tmp12 - tmp12;
        tmp12 = (((ISLOW_MULT_TYPE)(inptr[1 * 16])) * (quantptr[1 * 16]));
        tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        wsptr[3 * 0] = (int)((tmp10 + tmp0) >> (13 - 2));
        wsptr[3 * 2] = (int)((tmp10 - tmp0) >> (13 - 2));
        wsptr[3 * 1] = (int)((tmp2) >> (13 - 2));
    }
}
