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
for (j = 1; j <= i__1; ++j) {
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real denom = dlamda[i__] - dlamda[j];
        if (denom != 0.0) {
            w[i__] *= q[i__ + j * q_dim1] / denom;
        }
    }
    i__2 = *k;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        real denom = dlamda[i__] - dlamda[j];
        if (denom != 0.0) {
            w[i__] *= q[i__ + j * q_dim1] / denom;
        }
    }
}
}
