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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp10 <<= 13;
    tmp10 += ((INT32)1) << (13 - 2 - 1);
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp20 = ((tmp12) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp10 + tmp20;
    tmp21 = ((tmp10 - tmp20 - tmp20) >> (13 - 2));
    tmp20 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp10 = ((tmp20) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp11 + tmp10;
    tmp22 = tmp11 - tmp10;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp11 = ((z1 + z3) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp11 + ((z1 + z2) << 13);
    tmp12 = tmp11 + ((z3 - z2) << 13);
    tmp11 = (z1 - z2 - z3) << 2;
    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[8 * 5] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[8 * 1] = (int)(tmp21 + tmp11);
    wsptr[8 * 4] = (int)(tmp21 - tmp11);
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp22 - tmp12) >> (13 - 2));
}

}
