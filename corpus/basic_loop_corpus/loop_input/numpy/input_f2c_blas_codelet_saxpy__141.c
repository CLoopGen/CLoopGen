#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *sa;
real *sx;
integer *incx;
real *sy;
integer *incy;
integer i__1;
integer i__;
integer ix;
integer iy;

static real sa_data = 1.5f;
static real *sx_data;
static real *sy_data;
static integer incx_data;
static integer incy_data;

void init_vars() {
    i__1 = 10000000;  

    sx_data = (real*)aligned_alloc(32, i__1 * sizeof(real));
    sy_data = (real*)aligned_alloc(32, i__1 * sizeof(real));

    for (int i = 0; i < i__1; ++i) {
        sx_data[i] = (real)(i % 128) + 1.0f;
        sy_data[i] = (real)((i % 64) + 1) * 0.5f;
    }

    sa = &sa_data;
    sx = sx_data;
    sy = sy_data;
    incx = &incx_data;
    incy = &incy_data;

    *incx = 1;
    *incy = 1;

    i__ = 1;
    ix = 0;
    iy = 0;
}