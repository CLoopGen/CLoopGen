#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer n_storage;
doublereal *a_storage;
doublereal *x_storage;
integer incx_storage;
integer a_dim1_storage;
integer i__;
integer j;
integer ix;
integer jx;
doublereal temp;
logical nounit;

integer *n = &n_storage;
doublereal *a = NULL;
doublereal *x = NULL;
integer *incx = &incx_storage;
integer a_dim1 = 0;

void init_vars() {
    n_storage = 2048;
    incx_storage = 1;
    a_dim1_storage = n_storage;
    a_dim1 = a_dim1_storage;
    nounit = 1;

    a_storage = (doublereal*)aligned_alloc(32, sizeof(doublereal) * n_storage * a_dim1_storage);
    x_storage = (doublereal*)aligned_alloc(32, sizeof(doublereal) * n_storage * abs(incx_storage));

    a = a_storage;
    x = x_storage;

    for (integer i = 0; i < n_storage; ++i) {
        for (integer j = 0; j < a_dim1_storage; ++j) {
            a[i + j * a_dim1] = sin(i + j) * 0.1;
        }
    }

    for (integer i = 0; i < n_storage; ++i) {
        x[i * abs(incx_storage)] = cos(i) * 0.5;
    }

    jx = (n_storage - 1) * abs(incx_storage);
}