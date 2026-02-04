#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *sx;
integer *incx;
real *sy;
integer *incy;
integer i__1;
integer i__;
integer ix;
integer iy;
real stemp;

static real sx_data[65536];
static real sy_data[65536];

void init_vars() {
    i__1 = 65536;
    stemp = 0.0f;
    ix = 0;
    iy = 0;

    const int base_incx = 1;
    const int base_incy = 1;

    incx = (integer*)malloc(sizeof(integer));
    *incx = base_incx;
    incy = (integer*)malloc(sizeof(integer));
    *incy = base_incy;

    sx = sx_data;
    sy = sy_data;

    for (int i = 0; i < 65536; ++i) {
        sx[i] = (real)(i % 123 + 1);
        sy[i] = (real)(i % 456 + 1);
    }
}