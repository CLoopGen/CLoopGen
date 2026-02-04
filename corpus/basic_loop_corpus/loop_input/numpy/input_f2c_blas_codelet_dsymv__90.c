#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *alpha;
doublereal *a;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer iy;
integer jx;
integer jy;
doublereal temp1;
doublereal temp2;

static integer n_val = 2048;
static doublereal alpha_val = 1.5;
static integer incx_val = 1;
static integer incy_val = 1;

static doublereal *a_data;
static doublereal *x_data;
static doublereal *y_data;

void init_vars() {
    // Allocate arrays
    a_data = (doublereal *)calloc(n_val * n_val, sizeof(doublereal));
    x_data = (doublereal *)calloc(n_val, sizeof(doublereal));
    y_data = (doublereal *)calloc(n_val, sizeof(doublereal));

    // Initialize with non-zero values to simulate realistic computation
    for (integer i = 0; i < n_val; ++i) {
        x_data[i] = (doublereal)(i + 1);
        y_data[i] = (doublereal)(i % 7);
        for (integer j = 0; j < n_val; ++j) {
            a_data[i + j * n_val] = ((doublereal)((i + j) % 13)) / 17.0;
        }
    }

    // Set external pointers
    n = &n_val;
    alpha = &alpha_val;
    a = a_data;
    x = x_data;
    incx = &incx_val;
    y = y_data;
    incy = &incy_val;
    a_dim1 = n_val;
    i__1 = n_val;

    // Initialize loop indices and temps
    i__2 = 0;
    i__ = 0;
    j = 0;
    ix = 0;
    iy = 0;
    jx = 0;
    jy = 0;
    temp1 = 0.0;
    temp2 = 0.0;
}