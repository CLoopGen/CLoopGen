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
    integer j_offset = j * a_dim1;
    integer x_index = jx;
    if (x[x_index] != 0.F) {
        temp = x[x_index];
        integer ix_consec = kx;
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer a_index = i__ + j_offset;
            x[ix_consec] += temp * a[a_index];
            ix_consec += *incx;
        }
        if (nounit) {
            x[x_index] *= a[j_offset + j];
        }
    }
    jx += *incx;
}
}
