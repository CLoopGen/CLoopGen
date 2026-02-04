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



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp10 = ((JLONG)((unsigned long)(tmp10) << (13)));
    tmp10 += ((JLONG)1) << (13 - 1 - 1);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp20 = ((z2 - z3) * (((JLONG)((2.5466401319999998) * (((JLONG)1) << 13) + 0.5))));
    tmp23 = ((z2 - z1) * (((JLONG)((0.43081504500000001) * (((JLONG)1) << 13) + 0.5))));
    z4 = z1 + z3;
    tmp24 = ((z4) * (-((JLONG)((1.155664402) * (((JLONG)1) << 13) + 0.5))));
    z4 -= z2;
    tmp25 = tmp10 + ((z4) * (((JLONG)((1.3569279759999999) * (((JLONG)1) << 13) + 0.5))));
    tmp21 = tmp20 + tmp23 + tmp25 - ((z2) * (((JLONG)((1.821790775) * (((JLONG)1) << 13) + 0.5))));
    tmp20 += tmp25 + ((z3) * (((JLONG)((2.1158250870000002) * (((JLONG)1) << 13) + 0.5))));
    tmp23 += tmp25 - ((z1) * (((JLONG)((1.5135984769999999) * (((JLONG)1) << 13) + 0.5))));
    tmp24 += tmp25;
    tmp22 = tmp24 - ((z3) * (((JLONG)((0.78874911999999997) * (((JLONG)1) << 13) + 0.5))));
    tmp24 += ((z2) * (((JLONG)((1.9444135220000001) * (((JLONG)1) << 13) + 0.5)))) - ((z1) * (((JLONG)((1.3909757300000001) * (((JLONG)1) << 13) + 0.5))));
    tmp25 = tmp10 - ((z4) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

    if (tmp25 > 0) {
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
        tmp11 = z1 + z2;
        tmp14 = ((tmp11 + z3 + z4) * (((JLONG)((0.39843000299999998) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((JLONG)((0.88798390199999999) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((JLONG)((0.67036129499999997) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = tmp14 + ((z1 + z4) * (((JLONG)((0.36615157399999998) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((0.92310786600000005) * (((JLONG)1) << 13) + 0.5))));
        z1 = tmp14 - ((z2 + z3) * (((JLONG)((1.163011579) * (((JLONG)1) << 13) + 0.5))));
        tmp11 += z1 + ((z2) * (((JLONG)((2.0732765880000001) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += z1 - ((z3) * (((JLONG)((1.1921936230000001) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((z2 + z4) * (-((JLONG)((1.7982489100000001) * (((JLONG)1) << 13) + 0.5))));
        tmp11 += z1;
        tmp13 += z1 + ((z4) * (((JLONG)((2.1024586319999998) * (((JLONG)1) << 13) + 0.5))));
        tmp14 += ((z2) * (-((JLONG)((1.4672213009999999) * (((JLONG)1) << 13) + 0.5)))) + ((z3) * (((JLONG)((1.001388905) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.6848439070000001) * (((JLONG)1) << 13) + 0.5))));
    } else {
        tmp10 = tmp25;
        tmp11 = tmp25 >> 1;
        tmp12 = tmp25 >> 2;
        tmp13 = tmp25 >> 3;
        tmp14 = tmp25 >> 4;
    }

    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 1));
    wsptr[8 * 10] = (int)((tmp20 - tmp10) >> (13 - 1));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 1));
    wsptr[8 * 9] = (int)((tmp21 - tmp11) >> (13 - 1));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 1));
    wsptr[8 * 8] = (int)((tmp22 - tmp12) >> (13 - 1));
    wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 1));
    wsptr[8 * 7] = (int)((tmp23 - tmp13) >> (13 - 1));
    wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 1));
    wsptr[8 * 6] = (int)((tmp24 - tmp14) >> (13 - 1));
    wsptr[8 * 5] = (int)((tmp25) >> (13 - 1));
}
}
