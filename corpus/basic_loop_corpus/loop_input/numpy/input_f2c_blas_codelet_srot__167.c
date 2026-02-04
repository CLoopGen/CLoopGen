#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sx;
integer *incx;
real *sy;
integer *incy;
real *c__;
real *s;
integer i__1;
integer i__;
integer ix;
integer iy;
real stemp;

static real sx_data[65536];
static real sy_data[65536];
static real c_val = 0.86602540378f; // cos(30°)
static real s_val = 0.5f;           // sin(30°)
static integer incx_val = 1;
static integer incy_val = 1;

void init_vars() {
    const long n = 65536;
    i__1 = n;
    ix = 0;
    iy = 0;
    stemp = 0.0f;

    for (long i = 0; i < n; ++i) {
        sx_data[i] = (real)(i % 1000) * 0.01f;
        sy_data[i] = (real)((i + 500) % 1000) * 0.01f;
    }

    sx = sx_data;
    sy = sy_data;
    c__ = &c_val;
    s = &s_val;
    incx = &incx_val;
    incy = &incy_val;
}