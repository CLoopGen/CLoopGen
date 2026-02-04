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
integer stride = *incx;
integer base_offset_x = 0;
integer base_offset_a = 0;
for (j = *n; j >= 1; --j) {
    integer j_index = base_offset_x + j * stride;
    if (x[j_index] != 0.F) {
        temp = x[j_index];
        integer i_index = base_offset_x + *n * stride;
        i__1 = j + 1;
        for (i__ = *n; i__ >= i__1; --i__) {
            integer a_index = base_offset_a + (i__ + j * a_dim1);
            integer x_update_index = base_offset_x + i__ * stride;
            x[x_update_index] += temp * a[a_index];
            i_index -= stride;
        }
        if (nounit) {
            integer diag_a_index = base_offset_a + (j + j * a_dim1);
            x[j_index] *= a[diag_a_index];
        }
    }
}
}
