#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *cx;
integer *incx;
doublecomplex *cy;
integer *incy;
doublereal *c__;
doublereal *s;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer ix;
integer iy;
doublecomplex ctemp;

void init_vars() {
    const size_t n = 1000000;  

    cx = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));
    cy = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));

    for (size_t i = 0; i < n; ++i) {
        cx[i].r = 1.0 + i * 0.001;
        cx[i].i = 0.5 - i * 0.0005;
        cy[i].r = 2.0 + i * 0.0003;
        cy[i].i = -1.0 + i * 0.0007;
    }

    incx = (integer*)aligned_alloc(32, sizeof(integer));
    incy = (integer*)aligned_alloc(32, sizeof(integer));
    c__ = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    s = (doublereal*)aligned_alloc(32, sizeof(doublereal));

    *incx = 1;
    *incy = 1;
    *c__ = 0.866;  
    *s = 0.5;     

    i__1 = n;  

    i__ = 0;
    ix = 0;
    iy = 0;

    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    ctemp.r = 0.0; ctemp.i = 0.0;
}