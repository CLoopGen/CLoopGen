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
real temp_local;
integer j_temp = *n;
integer jx_temp = jx;
for (j = 1; j <= j_temp; ++j) {
    integer jx_current = jx_temp + (j - j_temp - 1) * (*incx);
    temp_local = x[jx_current];
    integer ix_current = jx_current;
    if (nounit) {
        temp_local *= a[j + j * a_dim1];
    }
    for (i__ = 1; i__ < j; ++i__) {
        ix_current += *incx;
        temp_local += a[i__ + j * a_dim1] * x[ix_current];
    }
    x[jx_current] = temp_local;
}
jx = jx_temp - (*n) * (*incx);
}
