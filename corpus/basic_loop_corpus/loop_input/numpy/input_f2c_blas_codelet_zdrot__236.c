#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *cx;
doublecomplex *cy;
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
doublecomplex ctemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~192 MB for two arrays of doublecomplex
    const size_t num_elements = data_size / sizeof(doublecomplex);

    cx = (doublecomplex*)aligned_alloc(32, num_elements * sizeof(doublecomplex));
    cy = (doublecomplex*)aligned_alloc(32, num_elements * sizeof(doublecomplex));
    c__ = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    s = (doublereal*)aligned_alloc(32, sizeof(doublereal));

    if (!cx || !cy || !c__ || !s) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    *c__ = 0.86602540378; // cos(30°)
    *s = 0.5;             // sin(30°)

    for (size_t i = 0; i < num_elements; ++i) {
        cx[i].r = (doublereal)(i % 100) / 10.0;
        cx[i].i = (doublereal)((i + 10) % 100) / 15.0;
        cy[i].r = (doublereal)((i + 20) % 100) / 20.0;
        cy[i].i = (doublereal)((i + 30) % 100) / 25.0;
    }

    i__1 = (integer)(num_elements - 1);
    i__ = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;

    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    ctemp.r = 0.0; ctemp.i = 0.0;
}