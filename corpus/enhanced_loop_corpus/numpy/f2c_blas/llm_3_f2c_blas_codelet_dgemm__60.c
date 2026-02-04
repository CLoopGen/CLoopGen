#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer b_dim1;
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
    ptrdiff_t cj_off = (ptrdiff_t)j * c_dim1;
    ptrdiff_t bj_off = (ptrdiff_t)j * b_dim1;
    if (*beta == 0.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            c__[i__ + cj_off] = 0.;
        }
    } else if (*beta != 1.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            c__[i__ + cj_off] = *beta * c__[i__ + cj_off];
        }
    }
    for (l = 1; l <= *k; ++l) {
        if (b[l + bj_off] != 0.) {
            temp = *alpha * b[l + bj_off];
            ptrdiff_t al_off = (ptrdiff_t)l * a_dim1;
            for (i__ = 1; i__ <= *m; ++i__) {
                c__[i__ + cj_off] += temp * a[i__ + al_off];
            }
        }
    }
}
}
