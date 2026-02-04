#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp10 <<= 13;
        tmp10 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        tmp20 = ((z2 - z3) * (((INT32)((2.5466401319999998) * (((INT32)1) << 13) + 0.5))));
        tmp23 = ((z2 - z1) * (((INT32)((0.43081504500000001) * (((INT32)1) << 13) + 0.5))));
        z4 = z1 + z3;
        tmp24 = ((z4) * (-((INT32)((1.155664402) * (((INT32)1) << 13) + 0.5))));
        z4 -= z2;
        tmp25 = tmp10 + ((z4) * (((INT32)((1.3569279759999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp23 + tmp25 - ((z2) * (((INT32)((1.821790775) * (((INT32)1) << 13) + 0.5))));
        tmp20 += tmp25 + ((z3) * (((INT32)((2.1158250870000002) * (((INT32)1) << 13) + 0.5))));
        tmp23 += tmp25 - ((z1) * (((INT32)((1.5135984769999999) * (((INT32)1) << 13) + 0.5))));
        tmp24 += tmp25;
        tmp22 = tmp24 - ((z3) * (((INT32)((0.78874911999999997) * (((INT32)1) << 13) + 0.5))));
        tmp24 += ((z2) * (((INT32)((1.9444135220000001) * (((INT32)1) << 13) + 0.5)))) - ((z1) * (((INT32)((1.3909757300000001) * (((INT32)1) << 13) + 0.5))));
        tmp25 = tmp10 - ((z4) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

        // Introduce loop-carried dependency: tmp10_prev influences next iteration's z1 scaling
        static INT32 tmp10_prev = 0;
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1])) + (tmp10_prev >> 14);
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        tmp11 = z1 + z2;
        tmp14 = ((tmp11 + z3 + z4) * (((INT32)((0.39843000299999998) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((0.88798390199999999) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((INT32)((0.67036129499999997) * (((INT32)1) << 13) + 0.5))));
        tmp13 = tmp14 + ((z1 + z4) * (((INT32)((0.36615157399999998) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((INT32)((0.92310786600000005) * (((INT32)1) << 13) + 0.5))));
        z1 = tmp14 - ((z2 + z3) * (((INT32)((1.163011579) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1 + ((z2) * (((INT32)((2.0732765880000001) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z1 - ((z3) * (((INT32)((1.1921936230000001) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z2 + z4) * (-((INT32)((1.7982489100000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1;
        tmp13 += z1 + ((z4) * (((INT32)((2.1024586319999998) * (((INT32)1) << 13) + 0.5))));
        tmp14 += ((z2) * (-((INT32)((1.4672213009999999) * (((INT32)1) << 13) + 0.5)))) + ((z3) * (((INT32)((1.001388905) * (((INT32)1) << 13) + 0.5)))) - ((z4) * (((INT32)((1.6848439070000001) * (((INT32)1) << 13) + 0.5))));

        wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsptr[8 * 10] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 2));
        wsptr[8 * 9] = (int)((tmp21 - tmp11) >> (13 - 2));
        wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsptr[8 * 8] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 2));
        wsptr[8 * 7] = (int)((tmp23 - tmp13) >> (13 - 2));
        wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 2));
        wsptr[8 * 6] = (int)((tmp24 - tmp14) >> (13 - 2));
        wsptr[8 * 5] = (int)((tmp25) >> (13 - 2));

        tmp10_prev = tmp10; // WAW and loop-carried RAW dependency introduced
    }
}
