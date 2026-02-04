#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float INT64FLOAT;

extern INTFLOAT (*in)[2];
extern INTFLOAT (*out)[32][2];
extern  INTFLOAT filter[8];
extern int len;
extern int reverse;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++, in++) {
        INT64FLOAT re_in = ((filter[6]) * (in[6][0]));
        INT64FLOAT im_in = ((filter[6]) * (in[6][1]));
        INT64FLOAT re_op = 0.F;
        INT64FLOAT im_op = 0.F;

        // Introduce loop-carried dependency: accumulate results across iterations
        static INT64FLOAT acc_re_op = 0.F;
        static INT64FLOAT acc_im_op = 0.F;

        for (j = 0; j < 6; j += 2) {
            re_op += (INT64FLOAT)filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
            im_op += (INT64FLOAT)filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
        }

        // Update output using current and accumulated previous values (RAW + WAW dependency introduced)
        out[reverse][i][0] = (INTFLOAT)(re_in + re_op + acc_re_op);
        out[reverse][i][1] = (INTFLOAT)(im_in + im_op + acc_im_op);
        out[!reverse][i][0] = (INTFLOAT)(re_in - re_op - acc_re_op);
        out[!reverse][i][1] = (INTFLOAT)(im_in - im_op - acc_im_op);

        // Carry over current operation result to next iteration (loop-carried dependency)
        acc_re_op = re_op;
        acc_im_op = im_op;
    }
}
