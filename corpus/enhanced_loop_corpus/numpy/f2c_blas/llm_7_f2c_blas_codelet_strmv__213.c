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
    real temp_local;
    integer jx_local = jx;
    for (j = 1; j <= i__1; ++j) {
        temp_local = x[jx_local];
        if (temp_local != 0.F) {
            integer ix_local = kx;
            i__2 = j - 1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[ix_local] = x[ix_local] + temp_local * a[i__ + j * a_dim1];
                ix_local += *incx;
            }
            if (nounit) {
                x[jx_local] = x[jx_local] * a[j + j * a_dim1];
            }
        }
        jx_local += *incx;
    }
    jx = jx_local;
}
