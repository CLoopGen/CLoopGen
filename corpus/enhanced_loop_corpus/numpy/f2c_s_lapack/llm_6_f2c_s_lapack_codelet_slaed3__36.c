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
    real temp1, temp2;
    for (j = 1; j <= i__1; ++j) {
        temp1 = q[j * q_dim1 + 1];
        temp2 = q[j * q_dim1 + 2];
        w[1] = temp1;
        w[2] = temp2;
        ii = indx[1];
        q[j * q_dim1 + 1] = w[ii];
        ii = indx[2];
        q[j * q_dim1 + 2] = w[ii];
    }
}
