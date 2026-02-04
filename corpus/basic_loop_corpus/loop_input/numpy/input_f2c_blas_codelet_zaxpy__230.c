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
doublecomplex *zy;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
integer i__;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assuming typical CPU speed, aim for moderate data size (~64-128MB of active data)
    const size_t n = 16777216; // 2^24 elements, about 256MB total for two arrays
    
    // Allocate arrays
    zx = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));
    
    // Initialize array elements to prevent undefined behavior
    for (size_t i = 0; i < n; ++i) {
        zx[i].r = 0.1 * (i % 7 + 1);
        zx[i].i = 0.2 * (i % 5 + 1);
        zy[i].r = 0.3 * (i % 3 + 1);
        zy[i].i = 0.4 * (i % 2 + 1);
    }
    
    // Allocate and initialize za
    za = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex));
    za->r = 0.5;
    za->i = 0.25;
    
    // Set loop bounds to stay within allocated memory
    i__1 = n - 1; // ensures i__ from 1 to i__1 accesses valid indices
    i__ = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    
    // Initialize temporaries
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
}