#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i1, i2;
    int unroll_factor = 4;
    int outer_len = len4 / unroll_factor;
    int remainder = len4 % unroll_factor;

    // Fully unrolled main loop with depth increased by manual unrolling simulation
    for (i1 = 0; i1 < outer_len; i1++) {
        int base_idx0 = 4 * (i1 * unroll_factor + 0);
        int base_idx1 = 4 * (i1 * unroll_factor + 1);
        int base_idx2 = 4 * (i1 * unroll_factor + 2);
        int base_idx3 = 4 * (i1 * unroll_factor + 3);

        y[base_idx0]     += alpha * x[base_idx0];
        y[base_idx0 + 1] += alpha * x[base_idx0 + 1];
        y[base_idx0 + 2] += alpha * x[base_idx0 + 2];
        y[base_idx0 + 3] += alpha * x[base_idx0 + 3];

        y[base_idx1]     += alpha * x[base_idx1];
        y[base_idx1 + 1] += alpha * x[base_idx1 + 1];
        y[base_idx1 + 2] += alpha * x[base_idx1 + 2];
        y[base_idx1 + 3] += alpha * x[base_idx1 + 3];

        y[base_idx2]     += alpha * x[base_idx2];
        y[base_idx2 + 1] += alpha * x[base_idx2 + 1];
        y[base_idx2 + 2] += alpha * x[base_idx2 + 2];
        y[base_idx2 + 3] += alpha * x[base_idx2 + 3];

        y[base_idx3]     += alpha * x[base_idx3];
        y[base_idx3 + 1] += alpha * x[base_idx3 + 1];
        y[base_idx3 + 2] += alpha * x[base_idx3 + 2];
        y[base_idx3 + 3] += alpha * x[base_idx3 + 3];
    }

    // Handle remaining iterations
    for (i2 = outer_len * unroll_factor; i2 < len4; i2++) {
        y[4 * i2]       += alpha * x[4 * i2];
        y[4 * i2 + 1]   += alpha * x[4 * i2 + 1];
        y[4 * i2 + 2]   += alpha * x[4 * i2 + 2];
        y[4 * i2 + 3]   += alpha * x[4 * i2 + 3];
    }
}
