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
extern integer i__1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.F) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            for (i__ = *n; i__ >= i__1; --i__) {
                real product = temp * a[i__ + j * a_dim1];
                x[ix] = x[ix] + product;
                ix -= *incx;
            }
            if (nounit) {
                x[jx] = temp * a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
