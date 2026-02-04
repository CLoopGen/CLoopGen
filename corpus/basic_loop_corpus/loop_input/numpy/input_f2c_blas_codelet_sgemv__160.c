#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *a;
real *x;
integer *incx;
real *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jx;
real temp;

static real alpha_storage = 1.5f;
static integer m_storage = 2048;
static integer incx_storage = 1;
static integer a_dim1_storage = 2048;
static integer i__1_storage = 2048;

static real *a_storage = NULL;
static real *x_storage = NULL;
static real *y_storage = NULL;

void init_vars() {
    m = &m_storage;
    alpha = &alpha_storage;
    incx = &incx_storage;
    a_dim1 = a_dim1_storage;
    i__1 = i__1_storage;

    const size_t a_size = (size_t)(*m) * (size_t)i__1;
    const size_t x_size = (size_t)i__1;
    const size_t y_size = (size_t)(*m);

    a_storage = (real*)calloc(a_size, sizeof(real));
    x_storage = (real*)calloc(x_size, sizeof(real));
    y_storage = (real*)calloc(y_size, sizeof(real));

    if (!a_storage || !x_storage || !y_storage) {
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < a_size; ++i) {
        a_storage[i] = (real)(drand48());
    }
    for (size_t i = 0; i < x_size; ++i) {
        x_storage[i] = (real)(drand48() > 0.5 ? drand48() : 0.0);
    }
    for (size_t i = 0; i < y_size; ++i) {
        y_storage[i] = (real)(drand48());
    }

    a = a_storage;
    x = x_storage;
    y = y_storage;

    jx = 1;
    temp = 0.0f;
    i__ = 1;
    i__2 = 0;
}