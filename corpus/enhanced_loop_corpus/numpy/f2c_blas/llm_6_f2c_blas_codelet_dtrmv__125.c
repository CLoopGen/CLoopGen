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
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    temp = x[jx];
    ix = jx;
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    integer k = j - 1;
    for (i__ = 1; i__ <= k; ++i__) {
        ix -= *incx;
        temp += a[(j - i__) + j * a_dim1] * x[ix];
    }
    x[jx] = temp;
    jx -= *incx;
}
}
