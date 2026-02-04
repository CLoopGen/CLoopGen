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
    for (ctr = 8; ctr > 0; inptr++, quantptr++, wsptr++, ctr--) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            if (ctr == 8 - 2 || ctr == 8 - 4 || ctr == 8 - 6)
                continue;
            if ((inptr[8 * 1] | inptr[8 * 3] | inptr[8 * 5] | inptr[8 * 7]) == 0) {
                int dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
                wsptr[8 * 0] = dcval;
                wsptr[8 * 1] = dcval;
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
        }
    }
}
