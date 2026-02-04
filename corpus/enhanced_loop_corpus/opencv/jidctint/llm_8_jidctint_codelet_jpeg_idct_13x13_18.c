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
extern JLONG tmp15;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
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
for (ctr = 0; ctr < 4; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));
    z1 += ((JLONG)1) << (13 - 1 - 1);
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;
    tmp12 = ((tmp10) * (((JLONG)((1.155388986) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.096834933999999998) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp20 = ((z2) * (((JLONG)((1.373119086) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp22 = ((z2) * (((JLONG)((0.50148704099999997) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.31645013100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.48691473899999999) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp21 = ((z2) * (((JLONG)((1.0585540520000001) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp25 = ((z2) * (-((JLONG)((1.25222392) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.435816023) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.93730306399999996) * (((JLONG)1) << 13) + 0.5)))) - z1;
    tmp23 = ((z2) * (-((JLONG)((0.17046460799999999) * (((JLONG)1) << 13) + 0.5)))) - tmp12 - tmp13;
    tmp24 = ((z2) * (-((JLONG)((0.80336486900000004) * (((JLONG)1) << 13) + 0.5)))) + tmp12 - tmp13;
    tmp26 = ((tmp11 - z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5)))) + z1;

    wsptr[8 * 0] = (int)((tmp20) >> (13 - 1));
    wsptr[8 * 2] = (int)((tmp22) >> (13 - 1));
    wsptr[8 * 1] = (int)((tmp21) >> (13 - 1));
    wsptr[8 * 3] = (int)((tmp23) >> (13 - 1));
    wsptr[8 * 4] = (int)((tmp24) >> (13 - 1));
    wsptr[8 * 5] = (int)((tmp25) >> (13 - 1));
    wsptr[8 * 6] = (int)((tmp26) >> (13 - 1));
}
}
