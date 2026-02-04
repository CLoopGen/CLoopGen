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
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 4; ctr > 0; ctr--) {
        JCOEFPTR local_inptr = inptr;
        ISLOW_MULT_TYPE *local_quantptr = quantptr;
        int *local_wsptr = wsptr;

        if (local_inptr[8] == 0 && local_inptr[16] == 0 && local_inptr[24] == 0 &&
            local_inptr[32] == 0 && local_inptr[40] == 0 && local_inptr[48] == 0 && local_inptr[56] == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(local_inptr[0])) * (local_quantptr[0])) << 2;
            for (int i = 0; i < 8; i++) {
                local_wsptr[i] = dcval;
            }
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }

        z2 = (((ISLOW_MULT_TYPE)(local_inptr[0])) * (local_quantptr[0]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[32])) * (local_quantptr[32]));
        z2 <<= 13;
        z3 <<= 13;
        z2 += ((INT32)1) << (13 - 2 - 1);
        tmp0 = z2 + z3;
        tmp1 = z2 - z3;

        z2 = (((ISLOW_MULT_TYPE)(local_inptr[16])) * (local_quantptr[16]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[48])) * (local_quantptr[48]));
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp2 = z1 + ((z2) * (((INT32)6270)));
        tmp3 = z1 - ((z3) * (((INT32)15137)));

        tmp10 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        tmp11 = tmp1 + tmp3;
        tmp12 = tmp1 - tmp3;

        tmp0 = (((ISLOW_MULT_TYPE)(local_inptr[56])) * (local_quantptr[56]));
        tmp1 = (((ISLOW_MULT_TYPE)(local_inptr[40])) * (local_quantptr[40]));
        tmp2 = (((ISLOW_MULT_TYPE)(local_inptr[24])) * (local_quantptr[24]));
        tmp3 = (((ISLOW_MULT_TYPE)(local_inptr[8])) * (local_quantptr[8]));

        z2 = tmp0 + tmp2;
        z3 = tmp1 + tmp3;
        z1 = ((z2 + z3) * (((INT32)9633)));
        z2 = ((z2) * (-((INT32)16069))) + z1;
        z3 = ((z3) * (-((INT32)3196))) + z1;

        z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
        tmp0 = ((tmp0) * (((INT32)2446))) + z1 + z2;
        tmp3 = ((tmp3) * (((INT32)12299))) + z1 + z3;

        z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
        tmp1 = ((tmp1) * (((INT32)16819))) + z1 + z3;
        tmp2 = ((tmp2) * (((INT32)25172))) + z1 + z2;

        local_wsptr[0] = (int)((tmp10 + tmp3) >> (13 - 2));
        local_wsptr[7] = (int)((tmp10 - tmp3) >> (13 - 2));
        local_wsptr[1] = (int)((tmp11 + tmp2) >> (13 - 2));
        local_wsptr[6] = (int)((tmp11 - tmp2) >> (13 - 2));
        local_wsptr[2] = (int)((tmp12 + tmp1) >> (13 - 2));
        local_wsptr[5] = (int)((tmp12 - tmp1) >> (13 - 2));
        local_wsptr[3] = (int)((tmp13 + tmp0) >> (13 - 2));
        local_wsptr[4] = (int)((tmp13 - tmp0) >> (13 - 2));

        inptr++;
        quantptr++;
        wsptr++;
    }
}
