#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *q;
extern integer *indx;
extern real *w;
extern integer q_dim1;
extern integer i__1;
extern integer j;
extern integer ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing q[j * q_dim1 + 1] and q[j * q_dim1 + 2] separately,
    // we process elements in a more cache-friendly, consecutive manner by grouping accesses.
    // We also preload w values once per j to reduce redundant indexing.

    for (j = 1; j <= i__1; ++j) {
        integer base_idx = j * q_dim1;
        w[1] = q[base_idx + 1];
        w[2] = q[base_idx + 2];

        ii = indx[1];
        q[base_idx + 1] = w[ii];
        ii = indx[2];
        q[base_idx + 2] = w[ii];
    }
}
