#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        // Eliminate loop-carried dependencies by unrolling and reordering independent computations

        JLONG local_tmp10, local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25;
        JLONG local_z1, local_z2, local_z3, local_z4;
        JLONG local_tmp11, local_tmp12, local_tmp13, local_tmp14;

        // First block: even-indexed coefficients (0,2,4,6)
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

        local_tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        local_tmp10 = ((JLONG)((unsigned long)(local_tmp10) << (13))) + ((JLONG)1) << (13 - 1 - 1);

        local_tmp20 = ((local_z2 - local_z3) * (((JLONG)((2.5466401319999998) * (((JLONG)1) << 13) + 0.5))));
        local_tmp23 = ((local_z2 - local_z1) * (((JLONG)((0.43081504500000001) * (((JLONG)1) << 13) + 0.5))));
        local_z4 = local_z1 + local_z3;
        local_tmp24 = ((local_z4) * (-((JLONG)((1.155664402) * (((JLONG)1) << 13) + 0.5))));
        local_z4 -= local_z2;
        local_tmp25 = local_tmp10 + ((local_z4) * (((JLONG)((1.3569279759999999) * (((JLONG)1) << 13) + 0.5))));

        local_tmp21 = local_tmp20 + local_tmp23 + local_tmp25 - ((local_z2) * (((JLONG)((1.821790775) * (((JLONG)1) << 13) + 0.5))));
        local_tmp20 += local_tmp25 + ((local_z3) * (((JLONG)((2.1158250870000002) * (((JLONG)1) << 13) + 0.5))));
        local_tmp23 += local_tmp25 - ((local_z1) * (((JLONG)((1.5135984769999999) * (((JLONG)1) << 13) + 0.5))));
        local_tmp24 += local_tmp25;
        local_tmp22 = local_tmp24 - ((local_z3) * (((JLONG)((0.78874911999999997) * (((JLONG)1) << 13) + 0.5))));
        local_tmp24 += ((local_z2) * (((JLONG)((1.9444135220000001) * (((JLONG)1) << 13) + 0.5)))) - ((local_z1) * (((JLONG)((1.3909757300000001) * (((JLONG)1) << 13) + 0.5))));
        local_tmp25 = local_tmp10 - ((local_z4) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

        // Second block: odd-indexed coefficients (1,3,5,7) — fully independent now
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        local_tmp11 = local_z1 + local_z2;
        local_tmp14 = ((local_tmp11 + local_z3 + local_z4) * (((JLONG)((0.39843000299999998) * (((JLONG)1) << 13) + 0.5))));
        local_tmp11 = ((local_tmp11) * (((JLONG)((0.88798390199999999) * (((JLONG)1) << 13) + 0.5))));
        local_tmp12 = ((local_z1 + local_z3) * (((JLONG)((0.67036129499999997) * (((JLONG)1) << 13) + 0.5))));
        local_tmp13 = local_tmp14 + ((local_z1 + local_z4) * (((JLONG)((0.36615157399999998) * (((JLONG)1) << 13) + 0.5))));

        local_tmp10 = local_tmp11 + local_tmp12 + local_tmp13 - ((local_z1) * (((JLONG)((0.92310786600000005) * (((JLONG)1) << 13) + 0.5))));
        local_z1 = local_tmp14 - ((local_z2 + local_z3) * (((JLONG)((1.163011579) * (((JLONG)1) << 13) + 0.5))));
        local_tmp11 += local_z1 + ((local_z2) * (((JLONG)((2.0732765880000001) * (((JLONG)1) << 13) + 0.5))));
        local_tmp12 += local_z1 - ((local_z3) * (((JLONG)((1.1921936230000001) * (((JLONG)1) << 13) + 0.5))));
        local_z1 = ((local_z2 + local_z4) * (-((JLONG)((1.7982489100000001) * (((JLONG)1) << 13) + 0.5))));
        local_tmp11 += local_z1;
        local_tmp13 += local_z1 + ((local_z4) * (((JLONG)((2.1024586319999998) * (((JLONG)1) << 13) + 0.5))));
        local_tmp14 += ((local_z2) * (-((JLONG)((1.4672213009999999) * (((JLONG)1) << 13) + 0.5)))) + ((local_z3) * (((JLONG)((1.001388905) * (((JLONG)1) << 13) + 0.5)))) - ((local_z4) * (((JLONG)((1.6848439070000001) * (((JLONG)1) << 13) + 0.5))));

        // Final stores using computed values — no loop-carried dependencies
        wsptr[8 * 0] = (int)((local_tmp20 + local_tmp10) >> (13 - 1));
        wsptr[8 * 10] = (int)((local_tmp20 - local_tmp10) >> (13 - 1));
        wsptr[8 * 1] = (int)((local_tmp21 + local_tmp11) >> (13 - 1));
        wsptr[8 * 9] = (int)((local_tmp21 - local_tmp11) >> (13 - 1));
        wsptr[8 * 2] = (int)((local_tmp22 + local_tmp12) >> (13 - 1));
        wsptr[8 * 8] = (int)((local_tmp22 - local_tmp12) >> (13 - 1));
        wsptr[8 * 3] = (int)((local_tmp23 + local_tmp13) >> (13 - 1));
        wsptr[8 * 7] = (int)((local_tmp23 - local_tmp13) >> (13 - 1));
        wsptr[8 * 4] = (int)((local_tmp24 + local_tmp14) >> (13 - 1));
        wsptr[8 * 6] = (int)((local_tmp24 - local_tmp14) >> (13 - 1));
        wsptr[8 * 5] = (int)((local_tmp25) >> (13 - 1));
    }
}
