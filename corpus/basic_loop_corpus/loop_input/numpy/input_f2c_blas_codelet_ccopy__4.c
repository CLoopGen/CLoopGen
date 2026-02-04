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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB for input arrays (64M complex elements)
    const size_t num_elements = data_size / sizeof(singlecomplex);

    cx = (singlecomplex*)aligned_alloc(32, data_size);
    cy = (singlecomplex*)aligned_alloc(32, data_size);

    if (!cx || !cy) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; ++i) {
        cx[i].r = sinf(i & 0xFF);
        cx[i].i = cosf(i & 0xFF);
        cy[i].r = 0.0f;
        cy[i].i = 0.0f;
    }

    i__1 = (integer)(num_elements - 1);
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
}