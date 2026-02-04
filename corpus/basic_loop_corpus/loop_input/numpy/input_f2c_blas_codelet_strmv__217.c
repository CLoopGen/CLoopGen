#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer *incx;
integer a_dim1;
integer i__;
integer j;
integer ix;
integer jx;
real temp;
logical nounit;

static real *a_data;
static real *x_data;
static integer n_value;
static integer incx_value;

void init_vars() {
    n_value = 2048;
    incx_value = 1;
    a_dim1 = n_value;
    nounit = 1;

    n = &n_value;
    incx = &incx_value;

    size_t a_size = (size_t)n_value * (size_t)n_value;
    size_t x_size = (size_t)n_value * (size_t)abs(incx_value);

    a_data = (real*)calloc(a_size, sizeof(real));
    x_data = (real*)calloc(x_size, sizeof(real));

    if (!a_data || !x_data) {
        exit(1);
    }

    a = a_data;
    x = x_data;

    for (integer i = 0; i < n_value; ++i) {
        x[i * incx_value] = 1.0f;
        for (integer j = 0; j <= i; ++j) {
            a[j + i * a_dim1] = (i == j) ? 2.0f : 1.0f;
        }
    }

    jx = (n_value - 1) * abs(incx_value);
}

static void cleanup() {
    free(a_data);
    free(x_data);
}