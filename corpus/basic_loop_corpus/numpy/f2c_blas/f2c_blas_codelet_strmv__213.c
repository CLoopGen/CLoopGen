#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef int logical;

extern real *a;
extern real *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 1; j <= i__1; ++j) {
    if (x[jx] != 0.F) {
        temp = x[jx];
        ix = kx;
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            x[ix] += temp * a[i__ + j * a_dim1];
            ix += *incx;
        }
        if (nounit) {
            x[jx] *= a[j + j * a_dim1];
        }
    }
    jx += *incx;
}

}
