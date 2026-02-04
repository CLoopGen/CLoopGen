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
integer i__1;
integer i__;
integer ix;
integer iy;
real stemp;

static real sx_data[65536];
static real sy_data[65536];

void init_vars() {
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    *incx = 1;
    *incy = 1;

    i__1 = 65536;

    for (int i = 0; i < 65536; ++i) {
        sx_data[i] = sinf((float)(i % 100));
        sy_data[i] = cosf((float)(i % 100));
    }

    sx = sx_data;
    sy = sy_data;

    ix = 0;
    iy = 0;
    stemp = 0.0f;
}