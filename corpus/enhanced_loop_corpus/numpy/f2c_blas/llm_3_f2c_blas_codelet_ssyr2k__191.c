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
for (j = 1; j <= i__1; j += 2) {
    integer j1 = j;
    integer j2 = (j + 1 <= i__1) ? j + 1 : j1;
    if (*beta == 0.F) {
        for (i__ = 1; i__ <= j1; ++i__) {
            c__[i__ + j1 * c_dim1] = 0.F;
        }
        if (j2 != j1) {
            for (i__ = 1; i__ <= j2; ++i__) {
                c__[i__ + j2 * c_dim1] = 0.F;
            }
        }
    } else if (*beta != 1.F) {
        for (i__ = 1; i__ <= j1; ++i__) {
            c__[i__ + j1 * c_dim1] = *beta * c__[i__ + j1 * c_dim1];
        }
        if (j2 != j1) {
            for (i__ = 1; i__ <= j2; ++i__) {
                c__[i__ + j2 * c_dim1] = *beta * c__[i__ + j2 * c_dim1];
            }
        }
    }
    for (l = 1; l <= *k; ++l) {
        real a_jl1 = a[j1 + l * a_dim1];
        real b_jl1 = b[j1 + l * b_dim1];
        real a_jl2 = (j2 != j1) ? a[j2 + l * a_dim1] : 0.F;
        real b_jl2 = (j2 != j1) ? b[j2 + l * b_dim1] : 0.F;

        int cond1 = (a_jl1 != 0.F || b_jl1 != 0.F);
        int cond2 = (j2 != j1) && (a_jl2 != 0.F || b_jl2 != 0.F);

        if (cond1) {
            temp1 = *alpha * b_jl1;
            temp2 = *alpha * a_jl1;
            for (i__ = 1; i__ <= j1; ++i__) {
                c__[i__ + j1 * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
            }
        }
        if (cond2) {
            temp1 = *alpha * b_jl2;
            temp2 = *alpha * a_jl2;
            for (i__ = 1; i__ <= j2; ++i__) {
                c__[i__ + j2 * c_dim1] += a[i__ + l * a_dim1] * temp1 + b[i__ + l * b_dim1] * temp2;
            }
        }
    }
}
}
