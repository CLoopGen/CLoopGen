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
for (j = 1; j <= i__1; j += 2) {
    if (j <= i__1 && (x[j] != 0. || y[j] != 0.)) {
        temp1 = *alpha * y[j];
        temp2 = *alpha * x[j];
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[i__] * temp1 + y[i__] * temp2;
        }
    }
    if (j + 1 <= i__1 && (x[j+1] != 0. || y[j+1] != 0.)) {
        temp1 = *alpha * y[j+1];
        temp2 = *alpha * x[j+1];
        i__2 = j + 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + (j+1) * a_dim1] = a[i__ + (j+1) * a_dim1] + x[i__] * temp1 + y[i__] * temp2;
        }
    }
}
}
