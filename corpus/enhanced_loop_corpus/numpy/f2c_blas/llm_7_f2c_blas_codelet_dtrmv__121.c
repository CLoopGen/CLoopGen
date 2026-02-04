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
        integer local_jx = jx;
        if (x[local_jx] != 0.) {
            temp = x[local_jx];
            integer local_ix = kx;
            i__2 = j - 1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                integer index_a = i__ + j * a_dim1;
                integer index_x = local_ix;
                x[index_x] += temp * a[index_a];
                local_ix += *incx;
            }
            if (nounit) {
                x[local_jx] *= a[j + j * a_dim1];
            }
        }
        jx += *incx;
    }
}
