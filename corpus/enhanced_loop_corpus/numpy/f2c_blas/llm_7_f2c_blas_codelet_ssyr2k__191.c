#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *k;
    real beta_val = *beta;
    real alpha_val = *alpha;
    for (l = 1; l <= i__2; ++l) {
        real a_jl = a[j + l * a_dim1];
        real b_jl = b[j + l * b_dim1];
        if (a_jl != 0.F || b_jl != 0.F) {
            temp1 = alpha_val * b_jl;
            temp2 = alpha_val * a_jl;
            i__3 = j;
            for (i__ = 1; i__ <= i__3; ++i__) {
                real update = a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
                real *c_pos = &c__[i__ + j * c_dim1];
                if (l == 1) {
                    if (beta_val == 0.F) {
                        *c_pos = update;
                    } else if (beta_val == 1.F) {
                        *c_pos += update;
                    } else {
                        *c_pos = beta_val * (*c_pos) + update;
                    }
                } else {
                    *c_pos += update;
                }
            }
        }
    }
    if (*k == 0) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            if (*beta == 0.F) {
                c__[i__ + j * c_dim1] = 0.F;
            } else if (*beta != 1.F) {
                c__[i__ + j * c_dim1] *= *beta;
            }
        }
    }
}
}
