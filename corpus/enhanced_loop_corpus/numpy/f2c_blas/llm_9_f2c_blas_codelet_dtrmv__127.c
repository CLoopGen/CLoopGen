#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
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
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 <= 0) return;
temp = x[jx];
if (nounit) {
    temp *= a[1 + 1 * a_dim1];
}
i__2 = *n;
for (i__ = 2; i__ <= i__2; ++i__) {
    temp += a[i__ + 1 * a_dim1] * x[jx + (i__ - 1) * (*incx)];
}
x[jx] = temp;
jx += *incx;
for (j = 2; j <= i__1; ++j) {
    temp = x[jx];
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    x[jx] = temp;
    jx += *incx;
}
}
