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
extern INT32 tmp14;
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
    int indices[] = {0, 2, 4, 6, 1, 3, 5, 7};
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]));
        tmp0 <<= 13;
        tmp0 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[1]])) * (quantptr[indices[1]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[indices[2]])) * (quantptr[indices[2]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[indices[3]])) * (quantptr[indices[3]]));
        tmp3 = ((z3) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp1 = tmp0 + tmp3;
        tmp2 = tmp0 - tmp3 - tmp3;
        tmp0 = ((z1 - z2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 = tmp2 + tmp0;
        tmp14 = tmp2 - tmp0 - tmp0;
        tmp0 = ((z1 + z2) * (((INT32)((1.3289260490000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((INT32)((1.0833504410000001) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z2) * (((INT32)((0.245575608) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp1 + tmp0 - tmp3;
        tmp12 = tmp1 - tmp0 + tmp2;
        tmp13 = tmp1 - tmp2 + tmp3;
        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[4]])) * (quantptr[indices[4]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[indices[5]])) * (quantptr[indices[5]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[indices[6]])) * (quantptr[indices[6]]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[indices[7]])) * (quantptr[indices[7]]));
        z2 = ((z2) * (-((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1 + z3) * (((INT32)((0.90903895499999998) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((INT32)((0.48368952500000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp2 + tmp3 - z2;
        tmp1 = ((z3 - z4) * (((INT32)((1.392728481) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z2 - tmp1;
        tmp3 += z2 + tmp1;
        tmp1 = ((z1 - z3 - z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        wsptr[0] = (int)((tmp10 + tmp0) >> (13 - 2));
        wsptr[8] = (int)((tmp10 - tmp0) >> (13 - 2));
        wsptr[1] = (int)((tmp11 + tmp1) >> (13 - 2));
        wsptr[7] = (int)((tmp11 - tmp1) >> (13 - 2));
        wsptr[2] = (int)((tmp12 + tmp2) >> (13 - 2));
        wsptr[6] = (int)((tmp12 - tmp2) >> (13 - 2));
        wsptr[3] = (int)((tmp13 + tmp3) >> (13 - 2));
        wsptr[5] = (int)((tmp13 - tmp3) >> (13 - 2));
        wsptr[4] = (int)((tmp14) >> (13 - 2));
    }
}
