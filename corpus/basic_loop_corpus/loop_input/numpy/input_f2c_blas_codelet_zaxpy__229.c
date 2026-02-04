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

doublecomplex *za;
doublecomplex *zx;
integer *incx;
doublecomplex *zy;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer ix;
integer iy;

void init_vars() {
    // Allocate za as a single complex number
    za = (doublecomplex*)malloc(sizeof(doublecomplex));
    za->r = 1.5;
    za->i = -0.8;

    // Determine problem size: aim for ~100ms runtime
    // The loop has simple arithmetic; estimate based on memory access
    // Assume modern CPU does ~1e9 operations/sec, so ~1e7-1e8 iterations for 0.01s
    // Use 16 million elements to be safe and within 1MB-256MB data range
    const int n = 16000000;

    // Allocate zx and zy arrays of size n
    zx = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));

    // Initialize incx and incy as pointers to integers
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    *incx = 1;
    *incy = 1;

    // Initialize array elements to avoid NaN/inf issues
    for (int j = 0; j < n; ++j) {
        zx[j].r = (doublereal)(j % 1000) / 1000.0;
        zx[j].i = (doublereal)((j + 100) % 1000) / 1000.0;
        zy[j].r = (doublereal)((j + 200) % 1000) / 1000.0;
        zy[j].i = (doublereal)((j + 300) % 1000) / 1000.0;
    }

    // Set loop bound i__1 to ensure we don't exceed array bounds
    // We use the full array size but ensure ix and iy stay in range
    i__1 = n;

    // Initialize starting indices
    ix = 0;
    iy = 0;

    // Ensure initial values of i__2, i__3, i__4 are valid (will be overwritten in loop)
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;

    // Initialize temporaries
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
}