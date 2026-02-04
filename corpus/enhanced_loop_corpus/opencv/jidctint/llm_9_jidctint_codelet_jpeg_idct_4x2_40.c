#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern INT32 *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr += 2, inptr += 2, quantptr += 2, wsptr += 2) {
    INT32 tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    INT32 tmp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    wsptr[4 * 0] = tmp2 + tmp3;
    wsptr[4 * 1] = tmp2 - tmp3;

    if (ctr + 1 < 2) {
        INT32 tmp4 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        INT32 tmp5 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        (wsptr+1)[4 * 0] = tmp4 + tmp5;
        (wsptr+1)[4 * 1] = tmp4 - tmp5;
    }
}
}
