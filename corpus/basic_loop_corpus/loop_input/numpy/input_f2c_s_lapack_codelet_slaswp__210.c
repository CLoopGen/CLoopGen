#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *a;
integer *ipiv;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer k;
integer i1;
integer i2;
integer ip;
integer ix;
integer ix0;
integer inc;
real temp;

static real a_data[1 << 20];
static integer ipiv_data[1 << 18];
static integer incx_val = 1;

void init_vars() {
    const integer n = 1024;
    const integer m = 1024;
    
    a = a_data;
    ipiv = ipiv_data;
    incx = &incx_val;
    
    a_dim1 = m;
    i__1 = n;
    i__2 = n;
    i__3 = 1;
    i__4 = 31;
    i1 = 1;
    i2 = n;
    ix0 = 0;
    inc = 1;
    
    for (int idx = 0; idx < (1 << 18); ++idx) {
        ipiv_data[idx] = rand() % m + 1;
    }
}