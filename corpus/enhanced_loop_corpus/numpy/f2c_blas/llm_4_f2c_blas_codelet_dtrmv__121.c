#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

typedef int logical;

extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp = x[jx];
    ix = kx;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (temp != 0.) {
            x[ix] += temp * a[i__ + j * a_dim1];
        }
        ix += *incx;
    }
    if (nounit && temp != 0.) {
        x[jx] *= a[j + j * a_dim1];
    } else if (!nounit && temp == 0.) {
        x[jx] = 0.;
    }
    jx += *incx;
}
}
