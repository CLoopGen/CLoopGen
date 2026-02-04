#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;
typedef int logical;

real *a;
real *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
real temp;
logical nounit;

static real a_data[1024 * 1024]; 
static real x_data[1024 * 512];
static integer incx_data = 1;

void init_vars() {
    const int size = 1000;
    i__1 = size; 
    a_dim1 = size;
    kx = 0;
    jx = 0;
    nounit = 1;

    a = a_data;
    x = x_data;
    incx = &incx_data;

    for (int i = 0; i < size; ++i) {
        x[i] = (real)(i % 7 != 0 ? 1.0f : 0.0f);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i + j * a_dim1] = (real)((i + j) % 13) / 13.0f;
        }
    }
}