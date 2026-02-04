#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of complex data (64M elements)
    const size_t num_elements = data_size / sizeof(singlecomplex);

    cx = (singlecomplex*)aligned_alloc(32, data_size);
    cy = (singlecomplex*)aligned_alloc(32, data_size);

    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    if (!cx || !cy || !incx || !incy) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    *incx = 1;
    *incy = 1;

    i__1 = num_elements;
    ix = 0;
    iy = 0;

    for (size_t i = 0; i < num_elements; ++i) {
        cx[i].r = (real)(rand()) / RAND_MAX;
        cx[i].i = (real)(rand()) / RAND_MAX;
        cy[i].r = 0.0f;
        cy[i].i = 0.0f;
    }
}