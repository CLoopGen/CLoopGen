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
    // Strided memory access with reversed input indexing pattern
    for (i = 0; i < len; i++) {
        int rev_i = len - 1 - i;  // Reverse traversal of input
        INT64FLOAT re_in = ((filter[6]) * (in[rev_i][0]));
        INT64FLOAT im_in = ((filter[6]) * (in[rev_i][1]));
        INT64FLOAT re_op = 0.F;
        INT64FLOAT im_op = 0.F;
        for (j = 0; j < 6; j += 2) {
            int forward_idx = j + 1;
            int mirror_idx = 12 - j - 1;
            // Strided access: using non-consecutive offsets in filter and in
            re_op += (INT64FLOAT)filter[forward_idx] * (in[rev_i + forward_idx][0] + in[rev_i + mirror_idx][0]);
            im_op += (INT64FLOAT)filter[forward_idx] * (in[rev_i + forward_idx][1] + in[rev_i + mirror_idx][1]);
        }
        out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
        out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
        out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
        out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
    }
}
