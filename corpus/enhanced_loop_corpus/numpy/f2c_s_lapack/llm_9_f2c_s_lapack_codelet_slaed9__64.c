#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *q;
extern real *dlamda;
extern real *w;
extern integer q_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; j += 2) {
    integer upper1 = j - 1;
    for (i__ = 1; i__ <= upper1; ++i__) {
        real inv_denom = 1.0f / (dlamda[i__] - dlamda[j]);
        w[i__] *= q[i__ + j * q_dim1] * inv_denom;
    }
    i__2 = *k;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        real inv_denom = 1.0f / (dlamda[i__] - dlamda[j]);
        w[i__] *= q[i__ + j * q_dim1] * inv_denom;
    }
    if (j + 1 <= i__1) {
        integer next_j = j + 1;
        integer upper2 = next_j - 1;
        for (i__ = 1; i__ <= upper2; ++i__) {
            real inv_denom = 1.0f / (dlamda[i__] - dlamda[next_j]);
            w[i__] *= q[i__ + next_j * q_dim1] * inv_denom;
        }
        for (i__ = next_j + 1; i__ <= *k; ++i__) {
            real inv_denom = 1.0f / (dlamda[i__] - dlamda[next_j]);
            w[i__] *= q[i__ + next_j * q_dim1] * inv_denom;
        }
    }
}
}
