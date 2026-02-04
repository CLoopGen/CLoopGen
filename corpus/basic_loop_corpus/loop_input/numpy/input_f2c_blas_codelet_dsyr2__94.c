#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *alpha;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
doublereal *a;
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

static doublereal alpha_val = 1.5;
static integer n_val = 1000;
static integer incx_val = 1;
static integer incy_val = 1;

static integer x_len = 1000;
static integer y_len = 1000;
static integer a_rows = 1000;
static integer a_cols = 1000;

static doublereal *x_arr;
static doublereal *y_arr;
static doublereal *a_arr;

void init_vars() {
    n = &n_val;
    alpha = &alpha_val;
    incx = &incx_val;
    incy = &incy_val;
    a_dim1 = a_rows;
    i__1 = n_val;

    x_arr = (doublereal*)calloc(x_len, sizeof(doublereal));
    y_arr = (doublereal*)calloc(y_len, sizeof(doublereal));
    a_arr = (doublereal*)calloc(a_rows * a_cols, sizeof(doublereal));

    if (!x_arr || !y_arr || !a_arr) {
        exit(1);
    }

    for (int i = 0; i < x_len; ++i) {
        x_arr[i] = sin(i);
    }
    for (int i = 0; i < y_len; ++i) {
        y_arr[i] = cos(i);
    }
    for (int i = 0; i < a_rows * a_cols; ++i) {
        a_arr[i] = 0.001;
    }

    x = x_arr;
    y = y_arr;
    a = a_arr;

    jx = 1;
    jy = 1;
    ix = 1;
    iy = 1;
    i__ = 1;
    temp1 = 0.0;
    temp2 = 0.0;
}