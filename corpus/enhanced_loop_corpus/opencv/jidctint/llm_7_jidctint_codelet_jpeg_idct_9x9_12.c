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



void loop(){
// Eliminate loop-carried dependencies by using local temporaries and reordering independent computations
for (ctr = 0; ctr < 8; ctr++) {
    JCOEFPTR local_inptr = inptr;
    ISLOW_MULT_TYPE *local_quantptr = quantptr;
    int *local_wsptr = wsptr;

    INT32 l_tmp0, l_tmp1, l_tmp2, l_tmp3;
    INT32 l_tmp10, l_tmp11, l_tmp12, l_tmp13, l_tmp14;
    INT32 l_z1, l_z2, l_z3, l_z4;

    l_tmp0 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (local_quantptr[8 * 0]));
    l_tmp0 <<= 13;
    l_tmp0 += ((INT32)1) << (13 - 2 - 1);

    l_z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
    l_z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 4])) * (local_quantptr[8 * 4]));
    l_z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));

    l_tmp3 = ((l_z3) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    l_tmp1 = l_tmp0 + l_tmp3;
    l_tmp2 = l_tmp0 - l_tmp3 - l_tmp3;
    l_tmp0 = ((l_z1 - l_z2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    l_tmp11 = l_tmp2 + l_tmp0;
    l_tmp14 = l_tmp2 - l_tmp0 - l_tmp0;

    l_tmp0 = ((l_z1 + l_z2) * (((INT32)((1.3289260490000001) * (((INT32)1) << 13) + 0.5))));
    l_tmp2 = ((l_z1) * (((INT32)((1.0833504410000001) * (((INT32)1) << 13) + 0.5))));
    l_tmp3 = ((l_z2) * (((INT32)((0.245575608) * (((INT32)1) << 13) + 0.5))));
    l_tmp10 = l_tmp1 + l_tmp0 - l_tmp3;
    l_tmp12 = l_tmp1 - l_tmp0 + l_tmp2;
    l_tmp13 = l_tmp1 - l_tmp2 + l_tmp3;

    l_z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 1])) * (local_quantptr[8 * 1]));
    l_z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 3])) * (local_quantptr[8 * 3]));
    l_z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 5])) * (local_quantptr[8 * 5]));
    l_z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 7])) * (local_quantptr[8 * 7]));

    l_z2 = ((l_z2) * (-((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    l_tmp2 = ((l_z1 + l_z3) * (((INT32)((0.90903895499999998) * (((INT32)1) << 13) + 0.5))));
    l_tmp3 = ((l_z1 + l_z4) * (((INT32)((0.48368952500000001) * (((INT32)1) << 13) + 0.5))));
    l_tmp0 = l_tmp2 + l_tmp3 - l_z2;

    l_tmp1 = ((l_z3 - l_z4) * (((INT32)((1.392728481) * (((INT32)1) << 13) + 0.5))));
    l_tmp2 += l_z2 - l_tmp1;
    l_tmp3 += l_z2 + l_tmp1;

    l_tmp1 = ((l_z1 - l_z3 - l_z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    local_wsptr[8 * 0] = (int)((l_tmp10 + l_tmp0) >> (13 - 2));
    local_wsptr[8 * 8] = (int)((l_tmp10 - l_tmp0) >> (13 - 2));
    local_wsptr[8 * 1] = (int)((l_tmp11 + l_tmp1) >> (13 - 2));
    local_wsptr[8 * 7] = (int)((l_tmp11 - l_tmp1) >> (13 - 2));
    local_wsptr[8 * 2] = (int)((l_tmp12 + l_tmp2) >> (13 - 2));
    local_wsptr[8 * 6] = (int)((l_tmp12 - l_tmp2) >> (13 - 2));
    local_wsptr[8 * 3] = (int)((l_tmp13 + l_tmp3) >> (13 - 2));
    local_wsptr[8 * 5] = (int)((l_tmp13 - l_tmp3) >> (13 - 2));
    local_wsptr[8 * 4] = (int)((l_tmp14) >> (13 - 2));

    // Update pointers manually without embedding them in for-loop increment
    inptr++;
    quantptr++;
    wsptr++;
}
}
