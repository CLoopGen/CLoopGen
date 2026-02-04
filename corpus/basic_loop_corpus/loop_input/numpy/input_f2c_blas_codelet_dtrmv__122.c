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
integer a_dim1;
integer i__1;
integer i__;
integer j;
doublereal temp;
logical nounit;

static doublereal a_data[2048 * 2048];
static doublereal x_data[2048];
static integer n_value;

void init_vars() {
    n_value = 2048;
    n = &n_value;
    a_dim1 = 2048;
    a = a_data;
    x = x_data;
    nounit = 1;

    for (integer idx = 0; idx < 2048; ++idx) {
        x[idx] = idx % 2 ? 1.0 : 0.0;
    }

    for (integer idx = 0; idx < 2048 * 2048; ++idx) {
        a[idx] = (idx % 137) * 0.01;
    }
}