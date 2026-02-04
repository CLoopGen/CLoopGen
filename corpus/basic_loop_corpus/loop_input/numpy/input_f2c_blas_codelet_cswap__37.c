#include <stdio.h>
#include <inttypes.h>
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
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer ix;
integer iy;
singlecomplex ctemp;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M complex numbers ~ 8MB total per array

    cx = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        cx[i].r = sinf(i);
        cx[i].i = cosf(i);
        cy[i].r = cosf(i + 1.0f);
        cy[i].i = sinf(i + 1.0f);
    }

    *incx = 1;
    *incy = 1;

    i__1 = (integer)(data_size * 0.5); // Run half the size to avoid out-of-bounds
    ix = 0;
    iy = 0;
}