#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *cx;
integer *incx;
singlecomplex *cy;
integer *incy;
real *c__;
real *s;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer ix;
integer iy;
singlecomplex ctemp;

void init_vars() {
    const size_t N = 8000000; // Approximate size for ~0.01 sec runtime (tuned for typical modern CPU)

    cx = (singlecomplex*)aligned_alloc(32, N * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, N * sizeof(singlecomplex));
    
    if (!cx || !cy) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    incx = (integer*)aligned_alloc(32, sizeof(integer));
    incy = (integer*)aligned_alloc(32, sizeof(integer));
    c__ = (real*)aligned_alloc(32, sizeof(real));
    s = (real*)aligned_alloc(32, sizeof(real));

    if (!incx || !incy || !c__ || !s) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    *incx = 1;
    *incy = 1;
    *c__ = 0.866f;  // cos(30°)
    *s = 0.5f;      // sin(30°)

    for (size_t i = 0; i < N; ++i) {
        cx[i].r = (real)(drand48() * 2.0 - 1.0);
        cx[i].i = (real)(drand48() * 2.0 - 1.0);
        cy[i].r = (real)(drand48() * 2.0 - 1.0);
        cy[i].i = (real)(drand48() * 2.0 - 1.0);
    }

    i__1 = (integer)(N / fmax(fabs(*incx), fabs(*incy))); 
    ix = 0;
    iy = 0;
}