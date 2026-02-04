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
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            real temp1 = q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
            real temp2 = q[i__ + (j+1) * q_dim1] / (dlamda[i__] - dlamda[j+1]);
            w[i__] *= temp1;
            w[i__] *= temp2;
        }
        i__2 = *k;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            real temp1 = q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
            real temp2 = q[i__ + (j+1) * q_dim1] / (dlamda[i__] - dlamda[j+1]);
            w[i__] *= temp1;
            w[i__] *= temp2;
        }
    } else {
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            w[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
        }
        i__2 = *k;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            w[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
        }
    }
}
}
