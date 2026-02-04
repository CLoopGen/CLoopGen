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
    JLONG local_tmp0, local_tmp1, local_tmp2, local_tmp3;
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << 13)) + ((JLONG)1 << 11);

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

        tmp3 = (z3 * ((JLONG)(0.707106781 * (1LL << 13) + 0.5)));
        local_tmp1 = tmp0 + tmp3;
        local_tmp2 = tmp0 - 2 * tmp3;

        tmp0 = ((z1 - z2) * ((JLONG)(0.707106781 * (1LL << 13) + 0.5)));
        tmp11 = local_tmp2 + tmp0;
        tmp14 = local_tmp2 - 2 * tmp0;

        tmp0 = ((z1 + z2) * ((JLONG)(1.328926049 * (1LL << 13) + 0.5)));
        tmp2 = (z1 * ((JLONG)(1.083350441 * (1LL << 13) + 0.5)));
        tmp3 = (z2 * ((JLONG)(0.245575608 * (1LL << 13) + 0.5)));
        tmp10 = local_tmp1 + tmp0 - tmp3;
        tmp12 = local_tmp1 - tmp0 + tmp2;
        tmp13 = local_tmp1 - tmp2 + tmp3;

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        z2 = (z2 * (-((JLONG)(1.224744871 * (1LL << 13) + 0.5))));

        local_tmp2 = ((z1 + z3) * ((JLONG)(0.909038955 * (1LL << 13) + 0.5)));
        local_tmp3 = ((z1 + z4) * ((JLONG)(0.483689525 * (1LL << 13) + 0.5)));
        local_tmp0 = local_tmp2 + local_tmp3 - z2;

        tmp1 = ((z3 - z4) * ((JLONG)(1.392728481 * (1LL << 13) + 0.5)));
        local_tmp2 += z2 - tmp1;
        local_tmp3 += z2 + tmp1;

        tmp1 = ((z1 - z3 - z4) * ((JLONG)(1.224744871 * (1LL << 13) + 0.5)));

        wsptr[0]       = (int)((tmp10 + local_tmp0) >> 12);
        wsptr[8]       = (int)((tmp10 - local_tmp0) >> 12);
        wsptr[1 * 8]   = (int)((tmp11 + tmp1) >> 12);
        wsptr[7 * 8]   = (int)((tmp11 - tmp1) >> 12);
        wsptr[2 * 8]   = (int)((tmp12 + local_tmp2) >> 12);
        wsptr[6 * 8]   = (int)((tmp12 - local_tmp2) >> 12);
        wsptr[3 * 8]   = (int)((tmp13 + local_tmp3) >> 12);
        wsptr[5 * 8]   = (int)((tmp13 - local_tmp3) >> 12);
        wsptr[4 * 8]   = (int)(tmp14 >> 12);
    }
}
