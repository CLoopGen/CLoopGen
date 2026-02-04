#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *alpha;
extern real *x;
extern integer *incx;
extern real *y;
extern integer *incy;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer iy;
extern integer jx;
extern integer jy;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer* restrict x_indices = (integer*)malloc(*n * sizeof(integer));
integer* restrict y_indices = (integer*)malloc(*n * sizeof(integer));
if (!x_indices || !y_indices) exit(1);
for (integer idx = 0; idx < *n; ++idx) {
    x_indices[idx] = 1 + idx * (*incx);
    y_indices[idx] = 1 + idx * (*incy);
}
for (j = 1; j <= i__1; ++j) {
    integer current_x_idx = x_indices[j - 1];
    integer current_y_idx = y_indices[j - 1];
    if (x[current_x_idx] != 0.F || y[current_y_idx] != 0.F) {
        temp1 = *alpha * y[current_y_idx];
        temp2 = *alpha * x[current_x_idx];
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            integer access_i = i__;
            integer access_j = j;
            a[access_i + access_j * a_dim1] = a[access_i + access_j * a_dim1] + 
                                              x[x_indices[i__ - 1]] * temp1 + 
                                              y[y_indices[i__ - 1]] * temp2;
        }
    }
}
free(x_indices);
free(y_indices);
}
