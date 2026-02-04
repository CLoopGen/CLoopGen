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
for (i = 0; i < len; i++ , in++) {
    // Eliminate partial dependencies by unrolling and reorganizing computations
    INT64FLOAT re_op = 0.F;
    INT64FLOAT im_op = 0.F;
    
    // Break loop-carried dependency by removing any state between iterations
    // Fully isolate each iteration (no static or global state used)

    // Unroll the inner loop manually to remove induction variable 'j' and expose parallelism
    int idx1 = 1, idx2 = 3, idx3 = 5;
    re_op += (INT64FLOAT)filter[idx1] * (in[idx1][0] + in[11][0]);
    im_op += (INT64FLOAT)filter[idx1] * (in[idx1][1] + in[11][1]);

    re_op += (INT64FLOAT)filter[idx2] * (in[idx2][0] + in[9][0]);
    im_op += (INT64FLOAT)filter[idx2] * (in[idx2][1] + in[9][1]);

    re_op += (INT64FLOAT)filter[idx3] * (in[idx3][0] + in[7][0]);
    im_op += (INT64FLOAT)filter[idx3] * (in[idx3][1] + in[7][1]);

    INT64FLOAT re_in = ((filter[6]) * (in[6][0]));
    INT64FLOAT im_in = ((filter[6]) * (in[6][1]));

    // Reorder stores to eliminate write-after-write (WAW) hazard on out[reverse][i]
    // Write to non-overlapping indices first
    out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
    out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
    out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
    out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
}
}
