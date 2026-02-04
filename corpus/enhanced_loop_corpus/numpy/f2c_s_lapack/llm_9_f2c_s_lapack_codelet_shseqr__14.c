#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1 - 1; i__ += 2) {
    integer idx1 = i__;
    integer idx2 = i__ + 1;
    wr[idx1] = h__[idx1 + idx1 * h_dim1];
    wi[idx1] = h__[idx1 + (idx1 - 1) * h_dim1] * 0.1F;
    wr[idx2] = h__[idx2 + idx2 * h_dim1];
    wi[idx2] = h__[idx2 + (idx2 - 1) * h_dim1] * 0.1F;
}
}
