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
singlecomplex q__1;
singlecomplex q__2;
integer i__;
singlecomplex ctemp;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB total for two arrays (each element is 8 bytes)
    
    cx = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));

    if (!cx || !cy) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        cx[idx].r = sinf(idx & 0xFF);
        cx[idx].i = cosf(idx & 0xFF);
        cy[idx].r = cosf(idx & 0xFF);
        cy[idx].i = sinf(idx & 0xFF);
    }

    i__1 = data_size - 1; // ensures i__ from 1 to i__1 stays within [0, data_size-1] index range
    i__ = 0;
    ctemp.r = 0.0f;
    ctemp.i = 0.0f;
    q__1.r = 0.0f;
    q__1.i = 0.0f;
    q__2.r = 0.0f;
    q__2.i = 0.0f;
    i__2 = 0;
    i__3 = 0;
}