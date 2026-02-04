#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp10 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 <<= 13;
    tmp0 += ((INT32)1) << (13 - 2 - 1);
    tmp1 = tmp0 + tmp10;
    tmp11 = ((tmp0 - tmp10 - tmp10) >> (13 - 2));
    tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp0 = ((tmp10) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp1 + tmp0;
    tmp12 = tmp1 - tmp0;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp1 = ((z1 + z3) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 + ((z1 + z2) << 13);
    tmp2 = tmp1 + ((z3 - z2) << 13);
    tmp1 = (z1 - z2 - z3) << 2;
    wsptr[3 * 0] = (int)((tmp10 + tmp0) >> (13 - 2));
    wsptr[3 * 5] = (int)((tmp10 - tmp0) >> (13 - 2));
    wsptr[3 * 1] = (int)(tmp11 + tmp1);
    wsptr[3 * 4] = (int)(tmp11 - tmp1);
    wsptr[3 * 2] = (int)((tmp12 + tmp2) >> (13 - 2));
    wsptr[3 * 3] = (int)((tmp12 - tmp2) >> (13 - 2));
}
}
