#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *n;
extern real *beta;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern real r__1;
extern singlecomplex q__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real beta_val = *beta;
integer n_val = *n;
for (j = 1; j <= i__1; ++j) {
    integer diag_index = j + j * c_dim1;
    c__[diag_index].r = beta_val * c__[diag_index].r;
    c__[diag_index].i = 0.F;

    for (i__ = j + 1; i__ <= n_val; ++i__) {
        integer idx = i__ + j * c_dim1;
        singlecomplex val = c__[idx];
        val.r *= beta_val;
        val.i *= beta_val;
        c__[idx] = val;
    }
}
}
