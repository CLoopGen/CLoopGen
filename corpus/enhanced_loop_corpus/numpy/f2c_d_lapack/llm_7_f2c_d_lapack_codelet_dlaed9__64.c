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
doublereal *restrict w_local = (doublereal*)malloc((*k + 1) * sizeof(doublereal));
if (w_local == NULL) return;
for (integer idx = 1; idx <= *k; ++idx) {
    w_local[idx] = w[idx];
}
for (j = 1; j <= i__1; ++j) {
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        w_local[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
    }
    i__2 = *k;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        w_local[i__] *= q[i__ + j * q_dim1] / (dlamda[i__] - dlamda[j]);
    }
}
for (integer idx = 1; idx <= *k; ++idx) {
    w[idx] = w_local[idx];
}
free(w_local);
}
