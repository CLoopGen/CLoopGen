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
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[16])) * (quantptr[16]));
    tmp10 = (tmp0 + tmp2) << 2;
    tmp12 = (tmp0 - tmp2) << 2;
    z2 = (((ISLOW_MULT_TYPE)(inptr[8])) * (quantptr[8]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[24])) * (quantptr[24]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    z1 += ((INT32)1) << (13 - 2 - 1);
    tmp0 = ((z1 + ((z2) * (((INT32)6270)))) >> (13 - 2));
    tmp2 = ((z1 - ((z3) * (((INT32)15137)))) >> (13 - 2));
    wsptr[0] = (int)(tmp10 + tmp0);
    wsptr[24] = (int)(tmp10 - tmp0);
    wsptr[8] = (int)(tmp12 + tmp2);
    wsptr[16] = (int)(tmp12 - tmp2);
}
}
