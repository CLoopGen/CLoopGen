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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 4; ctr > 0; ctr--) {
    INT32 local_dcval, local_in_0, local_quant_0;
    local_in_0 = (ISLOW_MULT_TYPE)(inptr[8 * 0]);
    local_quant_0 = (ISLOW_MULT_TYPE)(quantptr[8 * 0]);
    local_dcval = (local_in_0 * local_quant_0) << 2;

    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 &&
        inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        for (int i = 0; i < 8; i++) {
            wsptr[4 * i] = local_dcval;
        }
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    INT32 load_vals[8];
    for (int i = 0; i < 8; i++) {
        load_vals[i] = (ISLOW_MULT_TYPE)(inptr[8 * i]) * (quantptr[8 * i]);
    }

    z2 = load_vals[0] << 13;
    z3 = load_vals[4] << 13;
    z2 += ((INT32)1) << (13 - 2 - 1);
    tmp0 = z2 + z3;
    tmp1 = z2 - z3;

    z2 = load_vals[2];
    z3 = load_vals[6];
    z1 = (z2 + z3) * 4433;
    tmp2 = z1 + (z2 * 6270);
    tmp3 = z1 - (z3 * 15137);

    tmp10 = tmp0 + tmp2;
    tmp13 = tmp0 - tmp2;
    tmp11 = tmp1 + tmp3;
    tmp12 = tmp1 - tmp3;

    tmp0 = load_vals[7];
    tmp1 = load_vals[5];
    tmp2 = load_vals[3];
    tmp3 = load_vals[1];

    z2 = tmp0 + tmp2;
    z3 = tmp1 + tmp3;
    z1 = (z2 + z3) * 9633;
    z2 = z2 * (-16069) + z1;
    z3 = z3 * (-3196) + z1;

    z1 = (tmp0 + tmp3) * (-7373);
    tmp0 = tmp0 * 2446 + z1 + z2;
    tmp3 = tmp3 * 12299 + z1 + z3;

    z1 = (tmp1 + tmp2) * (-20995);
    tmp1 = tmp1 * 16819 + z1 + z3;
    tmp2 = tmp2 * 25172 + z1 + z2;

    wsptr[0] = (int)((tmp10 + tmp3) >> 11);
    wsptr[7] = (int)((tmp10 - tmp3) >> 11);
    wsptr[4] = (int)((tmp11 + tmp2) >> 11);
    wsptr[10] = (int)((tmp11 - tmp2) >> 11);
    wsptr[8] = (int)((tmp12 + tmp1) >> 11);
    wsptr[12] = (int)((tmp12 - tmp1) >> 11);
    wsptr[16] = (int)((tmp13 + tmp0) >> 11);
    wsptr[20] = (int)((tmp13 - tmp0) >> 11);

    inptr++;
    quantptr++;
    wsptr++;
}

}
