#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;
typedef int logical;

doublereal *a;
doublereal *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
doublereal temp;
logical nounit;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(doublereal))

void init_vars() {
    const integer n = 2048;  
    
    i__1 = n;
    a_dim1 = n;
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;
    nounit = 1;

    a = (doublereal*)aligned_alloc(32, sizeof(doublereal) * n * n);
    x = (doublereal*)aligned_alloc(32, sizeof(doublereal) * n);

    for (integer idx = 0; idx < n * n; ++idx) {
        a[idx] = sin(idx % 127);
    }
    for (integer idx = 0; idx < n; ++idx) {
        x[idx] = (idx % 5) ? 0.5 : 0.0;
    }

    kx = 0;
    jx = 0;
    ix = 0;
    i__ = 0;
    i__2 = 0;
    temp = 0.0;
}