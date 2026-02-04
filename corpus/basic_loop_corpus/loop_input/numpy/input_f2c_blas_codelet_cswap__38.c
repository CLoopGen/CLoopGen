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
singlecomplex *cy;
integer i__1;
integer i__2;
integer i__3;
integer i__;
singlecomplex ctemp;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M complex numbers ~ 8MB total data

    cx = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));

    for (size_t i = 0; i < data_size; ++i) {
        cx[i].r = sinf(i * 0.01f);
        cx[i].i = cosf(i * 0.01f);
        cy[i].r = cosf(i * 0.02f);
        cy[i].i = sinf(i * 0.02f);
    }

    i__1 = data_size - 1;
    i__ = 0;
    i__2 = 0;
    i__3 = 0;
    ctemp.r = 0.0f;
    ctemp.i = 0.0f;
}