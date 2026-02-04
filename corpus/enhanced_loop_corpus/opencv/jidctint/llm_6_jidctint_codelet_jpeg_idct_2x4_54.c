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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern INT32 *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp10 = (tmp0 + tmp2) << 13;
    tmp12 = (tmp0 - tmp2) << 13;
    tmp0 = z1 + ((z2) * (((INT32)6270)));
    tmp2 = z1 - ((z3) * (((INT32)15137)));
    wsptr[2 * 0] = tmp10 + tmp0;
    wsptr[2 * 3] = tmp10 - tmp0;
    wsptr[2 * 1] = tmp12 + tmp2;
    wsptr[2 * 2] = tmp12 - tmp2;
}
}
