#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
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
INT32 carry_tmp10 = 0, carry_tmp12 = 0;
for (ctr = 8; ctr > 0; ctr--, inptr++, quantptr++, wsptr++) {
    if (ctr == 8 - 4) {
        continue;
    }
    ISLOW_MULT_TYPE in_0 = (inptr[8 * 0]);
    ISLOW_MULT_TYPE in_1 = (inptr[8 * 1]);
    ISLOW_MULT_TYPE in_2 = (inptr[8 * 2]);
    ISLOW_MULT_TYPE in_3 = (inptr[8 * 3]);
    ISLOW_MULT_TYPE in_5 = (inptr[8 * 5]);
    ISLOW_MULT_TYPE in_6 = (inptr[8 * 6]);
    ISLOW_MULT_TYPE in_7 = (inptr[8 * 7]);

    ISLOW_MULT_TYPE q_0 = (quantptr[8 * 0]);
    ISLOW_MULT_TYPE q_1 = (quantptr[8 * 1]);
    ISLOW_MULT_TYPE q_2 = (quantptr[8 * 2]);
    ISLOW_MULT_TYPE q_3 = (quantptr[8 * 3]);
    ISLOW_MULT_TYPE q_5 = (quantptr[8 * 5]);
    ISLOW_MULT_TYPE q_6 = (quantptr[8 * 6]);
    ISLOW_MULT_TYPE q_7 = (quantptr[8 * 7]);

    if ((in_1 | in_2 | in_3 | in_5 | in_6 | in_7) == 0) {
        int dcval = (in_0 * q_0) << 2;
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        continue;
    }

    tmp0 = (in_0 * q_0) << (13 + 1);
    z2 = in_2 * q_2;
    z3 = in_6 * q_6;
    tmp2 = (z2 * ((INT32)15137)) - (z3 * ((INT32)6270));

    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;

    z1 = in_7 * q_7;
    z2 = in_5 * q_5;
    z3 = in_3 * q_3;
    z4 = in_1 * q_1;

    tmp0 = (-z1 * 1730) + (z2 * 11893) - (z3 * 17799) + (z4 * 8697);
    tmp2 = (-z1 * 4176) - (z2 * 4926) + (z3 * 7373) + (z4 * 20995);

    int shift_val = (13 - 2 + 1);
    int round = ((INT32)1) << (shift_val - 1);

    wsptr[8 * 0] = (int)((tmp10 + tmp2 + round) >> shift_val);
    wsptr[8 * 3] = (int)((tmp10 - tmp2 + round) >> shift_val);
    wsptr[8 * 1] = (int)((tmp12 + tmp0 + round) >> shift_val);
    wsptr[8 * 2] = (int)((tmp12 - tmp0 + round) >> shift_val);

    carry_tmp10 = tmp10;  
    carry_tmp12 = tmp12; 
}
}
