#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
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
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real beta_cij1 = *beta * c__[i__ + j * c_dim1];
        real beta_cij2 = (j + 1 <= i__1) ? *beta * c__[i__ + (j+1) * c_dim1] : 0.0F;
        c__[i__ + j * c_dim1] = (*beta == 0.F) ? 0.F : beta_cij1;
        if (j + 1 <= i__1) {
            c__[i__ + (j+1) * c_dim1] = (*beta == 0.F) ? 0.F : beta_cij2;
        }
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            real alpha_b_lj1 = *alpha * b[l + j * b_dim1];
            c__[i__ + j * c_dim1] += alpha_b_lj1 * a[i__ + l * a_dim1];
            if (j + 1 <= i__1 && b[l + (j+1) * b_dim1] != 0.F) {
                real alpha_b_lj2 = *alpha * b[l + (j+1) * b_dim1];
                c__[i__ + (j+1) * c_dim1] += alpha_b_lj2 * a[i__ + l * a_dim1];
            }
        }
    }
}
}
