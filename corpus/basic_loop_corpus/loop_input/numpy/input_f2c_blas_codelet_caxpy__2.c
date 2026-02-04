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

singlecomplex *ca;
singlecomplex *cx;
singlecomplex *cy;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB total data (adjustable)
    const size_t array_len = data_size / (2 * sizeof(singlecomplex)); // Two arrays: cx and cy

    // Allocate memory for cx and cy arrays
    cx = (singlecomplex*)aligned_alloc(32, array_len * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, array_len * sizeof(singlecomplex));

    // Initialize ca as a pointer to a single singlecomplex value
    ca = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex));
    ca->r = 1.5f;
    ca->i = -0.8f;

    // Initialize cx and cy with non-zero values to simulate realistic data
    for (size_t i = 0; i < array_len; ++i) {
        cx[i].r = sinf((float)i);
        cx[i].i = cosf((float)i);
        cy[i].r = -sinf((float)i);
        cy[i].i = cosf((float)i * 0.5f);
    }

    // Set loop bounds to ensure no out-of-bounds access
    i__1 = (integer)(array_len - 1); // ensures i__ <= i__1 stays in bounds for cx[i__4], cy[i__3], cy[i__2]
    i__ = 0; // Will be initialized in loop

    // Warm up the cache by touching data
    volatile real sink = cx[0].r + cy[0].r;
    (void)sink;
}