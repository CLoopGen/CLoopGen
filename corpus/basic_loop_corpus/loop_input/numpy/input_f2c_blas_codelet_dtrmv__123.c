#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *n;
doublereal *a;
doublereal *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
doublereal temp;
logical nounit;

static doublereal *a_data = NULL;
static doublereal *x_data = NULL;
static integer n_val;
static integer incx_val;

void init_vars() {
    n_val = 2048;
    incx_val = 1;

    n = &n_val;
    incx = &incx_val;
    a_dim1 = n_val;

    nounit = 1;

    a_data = (doublereal*)calloc(n_val * n_val, sizeof(doublereal));
    x_data = (doublereal*)calloc(n_val, sizeof(doublereal));

    for (int i = 0; i < n_val; ++i) {
        x_data[i] = (doublereal)(i + 1);
        for (int j = 0; j <= i; ++j) {
            a_data[i + j * a_dim1] = (doublereal)(i + j + 1);
        }
    }

    a = a_data;
    x = x_data;

    jx = (n_val - 1) * (*incx);
    kx = jx;
    temp = 0.0;
    i__1 = 0;
    i__ = 0;
    ix = 0;
}