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
    INT32 temp_accum = 0;
    for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
        tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        temp_accum += tmp10; // Introduce loop-carried dependency (WAW and RAW on temp_accum)
        wsptr[4 * 0] = temp_accum + tmp0;
        wsptr[4 * 1] = temp_accum - tmp0;
    }
}
