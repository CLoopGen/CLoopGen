#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *beta;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by flattening the index space
    // We reinterpret the access pattern to write to consecutive memory locations
    // assuming column-major layout and writing to the first i__1 elements in a packed vector form
    for (i__ = 0; i__ < i__1; ++i__) {
        i__2 = i__; // Consecutive access starting from base
        a[i__2].r = beta->r;
        a[i__2].i = beta->i;
    }
}
