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
    // Variant 1: Consecutive memory access pattern using array indexing with stride simulation
    // Instead of pointer arithmetic on 'in', use base pointer with explicit index and access elements consecutively
    // Also reorganize filter access to promote potential vectorization

    INTFLOAT (*base_in)[2] = in;  // Base pointer to input
    for (i = 0; i < len; i++) {
        int idx = i;
        INT64FLOAT re_in = ((filter[6]) * (base_in[idx + 6][0]));
        INT64FLOAT re_op = 0.F;
        INT64FLOAT im_in = ((filter[6]) * (base_in[idx + 6][1]));
        INT64FLOAT im_op = 0.F;

        for (j = 0; j < 6; j += 2) {
            int k = j + 1;
            re_op += (INT64FLOAT)filter[k] * (base_in[idx + k][0] + base_in[idx + 11 - j][0]);
            im_op += (INT64FLOAT)filter[k] * (base_in[idx + k][1] + base_in[idx + 11 - j][1]);
        }

        out[reverse][idx][0] = (INTFLOAT)(re_in + re_op);
        out[reverse][idx][1] = (INTFLOAT)(im_in + im_op);
        out[!reverse][idx][0] = (INTFLOAT)(re_in - re_op);
        out[!reverse][idx][1] = (INTFLOAT)(im_in - im_op);
    }
}
