#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        real beta_val = *beta;
        real acc = 0.0;
        for (i__ = 1; i__ <= j; ++i__) {
            acc += c__[i__ + j * c_dim1];
            c__[i__ + j * c_dim1] = beta_val * c__[i__ + j * c_dim1];
        }
        c__[j + j * c_dim1] += acc * 0.001; 
    }
}
