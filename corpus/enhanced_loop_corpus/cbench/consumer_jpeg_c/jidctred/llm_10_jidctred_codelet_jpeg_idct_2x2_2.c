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



void loop(){
for (ctr = 4; ctr > 0; inptr += 2, quantptr += 2, wsptr += 2, ctr--) {
    if ((inptr[8 * 1] | inptr[8 * 3]) == 0) {
        int dcval0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
        int dcval1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2])) << 2;
        wsptr[8 * 0] = dcval0;
        wsptr[8 * 1] = dcval0;
        wsptr[8 * 2] = dcval1;
        wsptr[8 * 3] = dcval1;
        continue;
    }
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp10 = z1 << (13 + 2);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    tmp0 = ((z1) * (-((INT32)5906)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp0 += ((z1) * (((INT32)6967)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp0 += ((z1) * (-((INT32)10426)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 += ((z1) * (((INT32)29692)));
    wsptr[8 * 0] = (int)(((tmp10 + tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
    wsptr[8 * 1] = (int)(((tmp10 - tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp10 = z1 << (13 + 2);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp0 = ((z1) * (-((INT32)5906)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp0 += ((z1) * (((INT32)6967)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp0 += ((z1) * (-((INT32)10426)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 += ((z1) * (((INT32)29692)));
    wsptr[8 * 2] = (int)(((tmp10 + tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
    wsptr[8 * 3] = (int)(((tmp10 - tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
}
}
