#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
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
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            temp = 0.;
            i__3 = *k;
            for (l = 1; l <= i__3; ++l) {
                temp += a[l + i__ * a_dim1] * a[l + j * a_dim1];
            }
            doublereal c_val = c__[i__ + j * c_dim1];
            if (*beta == 0.) {
                c__[i__ + j * c_dim1] = *alpha * temp;
            } else {
                c__[i__ + j * c_dim1] = *alpha * temp + *beta * c_val;
            }
        }
    }
}
