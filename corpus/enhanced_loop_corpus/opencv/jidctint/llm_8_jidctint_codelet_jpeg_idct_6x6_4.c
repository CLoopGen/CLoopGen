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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 12; ctr++, inptr++, quantptr++, wsptr++) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    tmp0 += ((JLONG)1) << (13 - 1 - 1);
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp10 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = tmp0 + tmp10;
    tmp11 = ((tmp0 - tmp10 - tmp10) >> (13 - 1));
    tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp0 = ((tmp10) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp1 + tmp0;
    tmp12 = tmp1 - tmp0;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp1 = ((z1 + z3) * (((JLONG)((0.366025404) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = tmp1 + ((JLONG)((unsigned long)(z1 + z2) << (13)));
    tmp2 = tmp1 + ((JLONG)((unsigned long)(z3 - z2) << (13)));
    tmp1 = ((JLONG)((unsigned long)(z1 - z2 - z3) << (1)));
    wsptr[6 * 0] = (int)((tmp10 + tmp0) >> (13 - 1));
    wsptr[6 * 5] = (int)((tmp10 - tmp0) >> (13 - 1));
    wsptr[6 * 1] = (int)(tmp11 + tmp1);
    wsptr[6 * 4] = (int)(tmp11 - tmp1);
    wsptr[6 * 2] = (int)((tmp12 + tmp2) >> (13 - 1));
    wsptr[6 * 3] = (int)((tmp12 - tmp2) >> (13 - 1));
}
}
