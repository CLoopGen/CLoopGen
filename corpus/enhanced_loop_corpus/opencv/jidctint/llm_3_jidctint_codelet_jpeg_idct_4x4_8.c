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
int indices[] = {0, 2, 1, 3};
for (ctr = 0; ctr < 4; ctr++ , inptr++ , quantptr++ , wsptr++) {
    int idx0 = indices[0], idx1 = indices[1], idx2 = indices[2], idx3 = indices[3];
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * idx0])) * (quantptr[8 * idx0]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * idx1])) * (quantptr[8 * idx1]));
    tmp10 = (tmp0 + tmp2) << 2;
    tmp12 = (tmp0 - tmp2) << 2;
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * idx2])) * (quantptr[8 * idx2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * idx3])) * (quantptr[8 * idx3]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    z1 += ((INT32)1) << (13 - 2 - 1);
    tmp0 = ((z1 + ((z2) * (((INT32)6270)))) >> (13 - 2));
    tmp2 = ((z1 - ((z3) * (((INT32)15137)))) >> (13 - 2));
    wsptr[4 * 0] = (int)(tmp10 + tmp0);
    wsptr[4 * 3] = (int)(tmp10 - tmp0);
    wsptr[4 * 1] = (int)(tmp12 + tmp2);
    wsptr[4 * 2] = (int)(tmp12 - tmp2);
}
}
