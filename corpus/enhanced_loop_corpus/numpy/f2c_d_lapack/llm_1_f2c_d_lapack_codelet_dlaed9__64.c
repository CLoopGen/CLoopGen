#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *q;
extern doublereal *dlamda;
extern doublereal *w;
extern integer q_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = j - 1;
    for (; i__2 >= 1; --i__2) {
        w[i__2] *= q[i__2 + j * q_dim1] / (dlamda[i__2] - dlamda[j]);
    }
    i__2 = *k;
    for (++j; j <= i__2; ++j) {
        for (i__ = 1; i__ <= *k; ++i__) {
            if (i__ != j) {
                w[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
            }
        }
    }
    break;
}
}
