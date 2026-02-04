#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    JLONG local_in[8], local_quant[8];
    for (int i = 0; i < 8; i++) {
        local_in[i] = inptr[8 * i];
        local_quant[i] = quantptr[8 * i];
    }

    if (local_in[1] == 0 && local_in[2] == 0 && local_in[3] == 0 && local_in[4] == 0 && local_in[5] == 0 && local_in[6] == 0 && local_in[7] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(local_in[0])) * (local_quant[0]))) << (1)));
        for (int i = 0; i < 8; i++) {
            wsptr[8 * i] = dcval;
        }
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    ISLOW_MULT_TYPE a0 = (ISLOW_MULT_TYPE)(local_in[0]), a1 = (ISLOW_MULT_TYPE)(local_in[1]);
    ISLOW_MULT_TYPE a2 = (ISLOW_MULT_TYPE)(local_in[2]), a3 = (ISLOW_MULT_TYPE)(local_in[3]);
    ISLOW_MULT_TYPE a4 = (ISLOW_MULT_TYPE)(local_in[4]), a5 = (ISLOW_MULT_TYPE)(local_in[5]);
    ISLOW_MULT_TYPE a6 = (ISLOW_MULT_TYPE)(local_in[6]), a7 = (ISLOW_MULT_TYPE)(local_in[7]);

    JLONG q0 = local_quant[0], q1 = local_quant[1], q2 = local_quant[2], q3 = local_quant[3];
    JLONG q4 = local_quant[4], q5 = local_quant[5], q6 = local_quant[6], q7 = local_quant[7];

    JLONG p2 = a2 * q2, p6 = a6 * q6;
    JLONG sum_26 = p2 + p6;
    z1 = sum_26 * 4433LL;
    tmp2 = z1 - (p6 * 15137LL);
    tmp3 = z1 + (p2 * 6270LL);

    JLONG p0 = a0 * q0, p4 = a4 * q4;
    tmp0 = (JLONG)((unsigned long)(p0 + p4) << 13);
    tmp1 = (JLONG)((unsigned long)(p0 - p4) << 13);
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    JLONG p7 = a7 * q7, p5 = a5 * q5, p3 = a3 * q3, p1 = a1 * q1;
    z1 = p7 + p1;
    z2 = p5 + p3;
    z3 = p7 + p3;
    z4 = p5 + p1;
    z5 = (z3 + z4) * 9633LL;

    tmp0 = p7 * 2446LL;
    tmp1 = p5 * 16819LL;
    tmp2 = p3 * 25172LL;
    tmp3 = p1 * 12299LL;

    z1 *= -7373LL;
    z2 *= -20995LL;
    z3 *= -16069LL;
    z4 *= -3196LL;

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    JLONG round = ((JLONG)1) << (12 - 1);
    wsptr[0]  = (int)((tmp10 + tmp3 + round) >> 12);
    wsptr[7]  = (int)((tmp10 - tmp3 + round) >> 12);
    wsptr[1]  = (int)((tmp11 + tmp2 + round) >> 12);
    wsptr[6]  = (int)((tmp11 - tmp2 + round) >> 12);
    wsptr[2]  = (int)((tmp12 + tmp1 + round) >> 12);
    wsptr[5]  = (int)((tmp12 - tmp1 + round) >> 12);
    wsptr[3]  = (int)((tmp13 + tmp0 + round) >> 12);
    wsptr[4]  = (int)((tmp13 - tmp0 + round) >> 12);

    inptr++;
    quantptr++;
    wsptr++;
}
}
