#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;
typedef int logical;

doublecomplex *a = NULL;
doublecomplex *x = NULL;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
doublecomplex temp;
logical nounit;

void init_vars() {
    const integer N = 4096;  

    i__1 = N;  
    a_dim1 = N;  
    nounit = 1;  

    a = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex) * N * N);
    x = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex) * N);

    for (integer idx = 0; idx < N * N; ++idx) {
        a[idx].r = sin(idx * 0.001);
        a[idx].i = cos(idx * 0.001);
    }

    for (integer idx = 0; idx < N; ++idx) {
        x[idx].r = (idx % 2 == 0) ? 0.5 : 0.0;
        x[idx].i = (idx % 2 == 1) ? 0.5 : 0.0;
    }

    i__ = 1;
    j = 1;
    temp.r = 0.0; temp.i = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
}