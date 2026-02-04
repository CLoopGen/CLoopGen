#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

typedef struct {
    real r;
    real i;
} singlecomplex;

singlecomplex *cx;
singlecomplex *cy;
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
singlecomplex ctemp;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements, adjust for ~0.01 sec runtime

    cx = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    c__ = (real*)aligned_alloc(32, sizeof(real));
    s = (real*)aligned_alloc(32, sizeof(real));

    if (!cx || !cy || !c__ || !s) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    *c__ = 0.866f; // cos(30°)
    *s = 0.5f;     // sin(30°)

    for (size_t i = 0; i < data_size; ++i) {
        cx[i].r = cosf(i * 0.01f);
        cx[i].i = sinf(i * 0.01f);
        cy[i].r = sinf(i * 0.015f);
        cy[i].i = cosf(i * 0.015f);
    }

    i__1 = data_size - 1;
    i__ = 0;
    q__1.r = q__1.i = 0.0f;
    q__2.r = q__2.i = 0.0f;
    q__3.r = q__3.i = 0.0f;
    ctemp.r = ctemp.i = 0.0f;
    i__2 = i__3 = i__4 = 0;
}