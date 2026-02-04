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
extern JLONG tmp14;
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
    JLONG carryover = 0;
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << 13)) + ((JLONG)1 << 11) + carryover;

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

        tmp3 = (z3 * ((JLONG)(0.707106781 * (1LL << 13) + 0.5)));
        tmp1 = tmp0 + tmp3;
        tmp2 = tmp0 - 2 * tmp3;

        tmp0 = ((z1 - z2) * ((JLONG)(0.707106781 * (1LL << 13) + 0.5)));
        tmp11 = tmp2 + tmp0;
        tmp14 = tmp2 - 2 * tmp0;

        tmp0 = ((z1 + z2) * ((JLONG)(1.328926049 * (1LL << 13) + 0.5)));
        tmp2 = (z1 * ((JLONG)(1.083350441 * (1LL << 13) + 0.5)));
        tmp3 = (z2 * ((JLONG)(0.245575608 * (1LL << 13) + 0.5)));
        tmp10 = tmp1 + tmp0 - tmp3;
        tmp12 = tmp1 - tmp0 + tmp2;
        tmp13 = tmp1 - tmp2 + tmp3;

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        z2 = (z2 * (-((JLONG)(1.224744871 * (1LL << 13) + 0.5))));

        tmp2 = ((z1 + z3) * ((JLONG)(0.909038955 * (1LL << 13) + 0.5)));
        tmp3 = ((z1 + z4) * ((JLONG)(0.483689525 * (1LL << 13) + 0.5)));
        tmp0 = tmp2 + tmp3 - z2;

        tmp1 = ((z3 - z4) * ((JLONG)(1.392728481 * (1LL << 13) + 0.5)));
        tmp2 += z2 - tmp1;
        tmp3 += z2 + tmp1;

        tmp1 = ((z1 - z3 - z4) * ((JLONG)(1.224744871 * (1LL << 13) + 0.5)));

        wsptr[0]     = (int)((tmp10 + tmp0) >> 12);
        wsptr[8]     = (int)((tmp10 - tmp0) >> 12);
        wsptr[8*1]   = (int)((tmp11 + tmp1) >> 12);
        wsptr[8*7]   = (int)((tmp11 - tmp1) >> 12);
        wsptr[8*2]   = (int)((tmp12 + tmp2) >> 12);
        wsptr[8*6]   = (int)((tmp12 - tmp2) >> 12);
        wsptr[8*3]   = (int)((tmp13 + tmp3) >> 12);
        wsptr[8*5]   = (int)((tmp13 - tmp3) >> 12);
        wsptr[8*4]   = (int)(tmp14 >> 12);

        carryover = (tmp10 + tmp0 + tmp11 + tmp1) >> 20;
    }
}
