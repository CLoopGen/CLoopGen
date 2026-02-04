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
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = 0.;
        i__3 = *k;
        const integer a_index_i = i__;
        const integer a_index_j = j;
        for (l = 1; l <= i__3; l += 2) {
            integer l1 = l;
            integer l2 = l + 1;
            if (l1 <= i__3) {
                temp += a[l1 + a_index_i * a_dim1] * a[l1 + a_index_j * a_dim1];
            }
            if (l2 <= i__3) {
                temp += a[l2 + a_index_i * a_dim1] * a[l2 + a_index_j * a_dim1];
            }
        }
        if (*beta == 0.) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
