#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *alpha;
extern real *a;
extern real *beta;
extern real *c__;
extern integer a_dim1;
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
for (j = 1; j <= i__1; ++j) {
    integer cj_base = j * c_dim1;
    integer aj_base = j * a_dim1;
    if (*beta == 0.F) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + cj_base] = 0.F;
        }
    } else if (*beta != 1.F) {
        for (i__ = 1; i__ <= j; ++i__) {
            c__[i__ + cj_base] = *beta * c__[i__ + cj_base];
        }
    }
    for (l = 1; l <= *k; ++l) {
        integer al_base = l * a_dim1;
        if (a[j + al_base] != 0.F) {
            temp = *alpha * a[j + al_base];
            for (i__ = 1; i__ <= j; ++i__) {
                c__[i__ + cj_base] += temp * a[i__ + al_base];
            }
        }
    }
}
}
