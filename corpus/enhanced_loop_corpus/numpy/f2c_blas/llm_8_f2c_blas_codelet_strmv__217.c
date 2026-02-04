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
for (j = *n; j >= 1; --j) {
    temp = x[jx];
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    ix = jx;
    for (i__ = j - 1; i__ >= 1; i__ -= 2) {
        ix -= *incx;
        temp += a[i__ + j * a_dim1] * x[ix];
        if (i__ > 1) {
            ix -= *incx;
            temp += a[i__ - 1 + j * a_dim1] * x[ix];
        }
    }
    x[jx] = temp;
    jx -= *incx;
}
}
