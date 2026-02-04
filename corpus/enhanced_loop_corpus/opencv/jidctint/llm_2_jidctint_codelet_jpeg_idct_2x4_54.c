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
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential array access)
    INT32 *local_wsptr = wsptr;
    JCOEFPTR local_inptr = inptr;
    ISLOW_MULT_TYPE *local_quantptr = quantptr;

    for (ctr = 0; ctr < 2; ctr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(local_inptr[0])) * (local_quantptr[0]));
        tmp2 = (((ISLOW_MULT_TYPE)(local_inptr[16])) * (local_quantptr[16]));
        tmp10 = (tmp0 + tmp2) << 13;
        tmp12 = (tmp0 - tmp2) << 13;

        z2 = (((ISLOW_MULT_TYPE)(local_inptr[8])) * (local_quantptr[8]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[24])) * (local_quantptr[24]));
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp0 = z1 + ((z2) * (((INT32)6270)));
        tmp2 = z1 - ((z3) * (((INT32)15137)));

        local_wsptr[0] = tmp10 + tmp0;
        local_wsptr[3] = tmp10 - tmp0;
        local_wsptr[1] = tmp12 + tmp2;
        local_wsptr[2] = tmp12 - tmp2;

        local_inptr++;
        local_quantptr++;
        local_wsptr += 4;
    }
}
