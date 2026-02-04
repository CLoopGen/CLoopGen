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
        ii = indx[1];
        w[1] = q[j * q_dim1 + 1];
        q[j * q_dim1 + 1] = w[ii];
        ii = indx[2];
        w[2] = q[j * q_dim1 + 2];
        q[j * q_dim1 + 2] = w[ii];
    }
}
