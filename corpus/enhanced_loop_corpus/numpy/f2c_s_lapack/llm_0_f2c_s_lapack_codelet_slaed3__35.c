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
    for (i__ = 1; i__ <= *k; ++i__) {
        if (i__ < j) {
            w[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
        } else if (i__ > j) {
            w[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
        }
    }
}
}
