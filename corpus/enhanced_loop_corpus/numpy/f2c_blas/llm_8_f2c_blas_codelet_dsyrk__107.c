#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    doublereal beta_val = *beta;
    doublereal alpha_val = *alpha;
    integer k_val = *k;
    integer cj_base = j * c_dim1;
    integer aj_base = j * a_dim1;

    if (beta_val != 1.) {
        for (i__ = 1; i__ <= j; ++i__) {
            integer idx = i__ + cj_base;
            c__[idx] = (beta_val == 0.0) ? 0.0 : beta_val * c__[idx];
        }
    }

    for (l = 1; l <= k_val; ++l) {
        integer al_base = l * a_dim1;
        doublereal a_jl = a[j + al_base];
        if (a_jl != 0.) {
            temp = alpha_val * a_jl;
            for (i__ = j; i__ >= 1; --i__) {  // Reverse loop direction: introduces WAR/WAW dependency change
                c__[i__ + cj_base] += temp * a[i__ + al_base];
            }
        }
    }
}
}
