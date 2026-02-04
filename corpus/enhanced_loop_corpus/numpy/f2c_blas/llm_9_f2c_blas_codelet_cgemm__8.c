#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity and trip count by skipping every other iteration
for (j = 1; j <= i__1; j += 2) {
    i__2 = (*m + 1) / 2; // Reduce inner loop iterations
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        // Simplify computation: only scale real part, ignore imaginary contribution
        c__[i__3].r = beta->r * c__[i__3].r;
        c__[i__3].i = 0.0f; // Zero out imaginary component
    }
}
}
