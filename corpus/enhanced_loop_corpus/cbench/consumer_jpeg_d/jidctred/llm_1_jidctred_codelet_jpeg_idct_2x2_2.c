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
    for (ctr = 8; ctr > 0; ctr -= 2) {
        for (int inner = 0; inner < 2 && ctr - inner > 0; inner++) {
            JCOEFPTR cur_inptr = inptr + inner;
            ISLOW_MULT_TYPE *cur_quantptr = quantptr + inner;
            int *cur_wsptr = wsptr + inner;
            int effective_ctr = ctr - inner;
            if (effective_ctr == 8 - 2 || effective_ctr == 8 - 4 || effective_ctr == 8 - 6)
                continue;
            if ((cur_inptr[8 * 1] | cur_inptr[8 * 3] | cur_inptr[8 * 5] | cur_inptr[8 * 7]) == 0) {
                int dcval = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 0])) * (cur_quantptr[8 * 0])) << 2;
                cur_wsptr[8 * 0] = dcval;
                cur_wsptr[8 * 1] = dcval;
                continue;
            }
            z1 = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 0])) * (cur_quantptr[8 * 0]));
            tmp10 = z1 << (13 + 2);
            z1 = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 7])) * (cur_quantptr[8 * 7]));
            tmp0 = ((z1) * (-((INT32)5906)));
            z1 = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 5])) * (cur_quantptr[8 * 5]));
            tmp0 += ((z1) * (((INT32)6967)));
            z1 = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 3])) * (cur_quantptr[8 * 3]));
            tmp0 += ((z1) * (-((INT32)10426)));
            z1 = (((ISLOW_MULT_TYPE)(cur_inptr[8 * 1])) * (cur_quantptr[8 * 1]));
            tmp0 += ((z1) * (((INT32)29692)));
            cur_wsptr[8 * 0] = (int)(((tmp10 + tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
            cur_wsptr[8 * 1] = (int)(((tmp10 - tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
        }
        inptr += 2;
        quantptr += 2;
        wsptr += 2;
    }
}
