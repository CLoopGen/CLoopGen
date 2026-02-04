#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

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
integer kx;
integer ky;
doublereal temp1;
doublereal temp2;

static doublereal alpha_data;
static doublereal *a_data;
static doublereal *x_data;
static doublereal *y_data;
static integer incx_data;
static integer incy_data;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, choose matrix size around 1000-2000
    a_dim1 = 2048;
    i__1 = 2048;  // outer loop bound

    // Allocate arrays
    a_data = (doublereal*)calloc(a_dim1 * a_dim1, sizeof(doublereal));
    x_data = (doublereal*)calloc(a_dim1, sizeof(doublereal));
    y_data = (doublereal*)calloc(a_dim1, sizeof(doublereal));

    // Initialize data
    for (int i = 0; i < a_dim1; ++i) {
        x_data[i] = 1.0 + i * 0.001;
        y_data[i] = 2.0 - i * 0.0005;
        for (int j = 0; j < a_dim1; ++j) {
            a_data[i + j * a_dim1] = (i == j) ? 2.0 : ((i > j) ? (0.1 + i*0.001) : 0.0);
        }
    }

    alpha_data = 0.5;
    incx_data = 1;
    incy_data = 1;

    // Initialize external pointers
    alpha = &alpha_data;
    a = a_data;
    x = x_data;
    incx = &incx_data;
    y = y_data;
    incy = &incy_data;

    // Initialize indexing variables
    kx = 1;
    ky = 1;
    jx = 1;
    jy = 1;

    // Initialize temporaries
    temp1 = 0.0;
    temp2 = 0.0;
    i__ = 1;
    i__2 = 1;
}