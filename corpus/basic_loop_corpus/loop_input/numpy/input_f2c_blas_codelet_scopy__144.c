#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

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

static real sx_data[65536];
static real sy_data[65536];
static integer incx_val = 1;
static integer incy_val = 1;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_sec * 1000 + tv.tv_usec / 1000));

    for (int i = 0; i < 65536; ++i) {
        sx_data[i] = (real)(rand() % 1000) / 10.0f;
        sy_data[i] = 0.0f;
    }

    sx = sx_data;
    sy = sy_data;
    incx = &incx_val;
    incy = &incy_val;
    i__1 = 65536;
    ix = 0;
    iy = 0;
}