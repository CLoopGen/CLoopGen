#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*n <= 0) return;
for (j = *n; j >= 2; j -= 2) {
    integer jx1 = jx;
    integer jx2 = jx - *incx;
    temp = x[jx1];
    real temp2 = x[jx2];
    integer ix1 = jx1;
    integer ix2 = jx2;
    if (nounit) {
        temp *= a[j + j * a_dim1];
        temp2 *= a[j-1 + (j-1) * a_dim1];
    }
    for (i__ = j - 1; i__ >= 1; --i__) {
        ix1 -= *incx;
        ix2 -= *incx;
        temp += a[i__ + j * a_dim1] * x[ix1];
        temp2 += a[i__ + (j-1) * a_dim1] * x[ix2];
    }
    x[jx1] = temp;
    x[jx2] = temp2;
    jx -= 2 * (*incx);
}
if (j == 1) {
    temp = x[jx];
    ix = jx;
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    for (i__ = j - 1; i__ >= 1; --i__) {
        ix -= *incx;
        temp += a[i__ + j * a_dim1] * x[ix];
    }
    x[jx] = temp;
    jx -= *incx;
}
}
