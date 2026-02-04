#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *q;
extern integer *indx;
extern doublereal *w;
extern integer q_dim1;
extern integer i__1;
extern integer j;
extern integer ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (int k = 1; k <= 2; ++k) {
        w[k] = q[j * q_dim1 + k];
    }
    for (int k = 1; k <= 2; ++k) {
        ii = indx[k];
        q[j * q_dim1 + k] = w[ii];
    }
}
}
