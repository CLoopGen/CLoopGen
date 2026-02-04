#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp1_local, temp2_local;
    for (j = 1; j <= i__1; ++j) {
        if (x[j] != 0. || y[j] != 0.) {
            temp1_local = *alpha * y[j];
            temp2_local = *alpha * x[j];
            i__2 = j;
            for (i__ = 1; i__ <= i__2; ++i__) {
                doublereal update = x[i__] * temp1_local + y[i__] * temp2_local;
                a[i__ + j * a_dim1] += update;
            }
        }
    }
}
