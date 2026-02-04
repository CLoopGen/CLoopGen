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

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D-like index into a stride-based linear pattern
    // Assuming row-major layout and that a_dim1 is the leading dimension, we step consecutively in memory
    doublecomplex *base = &a[a_dim1 + 1]; // Start at a[2 + a_dim1] equivalent
    for (i__ = 0; i__ < i__1 - 1; ++i__) {
        base[i__].r = 0.0;
        base[i__].i = 0.0;
    }
}
