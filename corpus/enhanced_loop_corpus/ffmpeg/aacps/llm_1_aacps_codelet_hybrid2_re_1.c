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
        INT64FLOAT re_op_part1 = 0.F, re_op_part2 = 0.F;
        INT64FLOAT im_op_part1 = 0.F, im_op_part2 = 0.F;

        for (j = 0; j < 3; j++) {
            int idx1 = 2*j + 1;
            int idx2 = 12 - idx1;
            re_op_part1 += (INT64FLOAT)filter[idx1] * in[idx1][0];
            re_op_part2 += (INT64FLOAT)filter[idx1] * in[idx2][0];
            im_op_part1 += (INT64FLOAT)filter[idx1] * in[idx1][1];
            im_op_part2 += (INT64FLOAT)filter[idx1] * in[idx2][1];
        }

        INT64FLOAT re_op = re_op_part1 + re_op_part2;
        INT64FLOAT im_op = im_op_part1 + im_op_part2;

        out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
        out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
        out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
        out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
    }
}
