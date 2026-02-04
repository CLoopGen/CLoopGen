#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *alpha;
real *a;
real *x;
real *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp1;
real temp2;

static real alpha_data;
static real *a_data;
static real *x_data;
static real *y_data;

void init_vars() {
    const long target_size_mb = 64;
    const long float_size = sizeof(real);
    const long total_elements = (target_size_mb * (1 << 20)) / float_size;

    a_dim1 = (integer)sqrt(total_elements / 2.0);
    i__1 = a_dim1;

    if (i__1 < 100) {
        i__1 = 100;
        a_dim1 = i__1;
    }

    size_t a_size = (size_t)a_dim1 * a_dim1;
    size_t x_size = (size_t)i__1;
    size_t y_size = (size_t)i__1;

    a_data = (real*)aligned_alloc(32, a_size * float_size);
    x_data = (real*)aligned_alloc(32, x_size * float_size);
    y_data = (real*)aligned_alloc(32, y_size * float_size);

    alpha = &alpha_data;
    a = a_data;
    x = x_data;
    y = y_data;

    *alpha = 1.5f;

    for (size_t i = 0; i < a_size; ++i) {
        a_data[i] = (real)(drand48() * 2.0 - 1.0);
    }
    for (integer i = 1; i <= i__1; ++i) {
        x_data[i] = (real)(drand48() * 2.0 - 1.0);
        y_data[i] = (real)(drand48() * 2.0 - 1.0);
    }

    j = 1;
    i__ = 1;
    temp1 = 0.0f;
    temp2 = 0.0f;
}