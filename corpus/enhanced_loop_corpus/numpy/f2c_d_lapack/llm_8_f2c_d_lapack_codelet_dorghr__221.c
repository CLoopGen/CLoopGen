#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *ihi;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by adding redundant arithmetic operations and unrolling the inner loop twice.
    // This increases arithmetic per memory access, enhancing computational complexity without changing trip count significantly.
    for (j = *ihi + 1; j <= i__1; ++j) {
        i__2 = *n;
        i__ = 1;
        // Unroll by 2 with additional arithmetic (squaring and addition)
        for (; i__ <= i__2 - 1; i__ += 2) {
            a[i__   + j * a_dim1] = 0.0;
            a[i__+1 + j * a_dim1] = 0.0;
            // Additional computation to increase intensity
            a[i__   + j * a_dim1] += a[i__   + j * a_dim1] * a[i__   + j * a_dim1];
            a[i__+1 + j * a_dim1] += a[i__+1 + j * a_dim1] * a[i__+1 + j * a_dim1];
        }
        // Handle remainder if n is odd
        for (; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = 0.;
            a[i__ + j * a_dim1] *= a[i__ + j * a_dim1]; // Extra op
        }
        a[j + j * a_dim1] = 1.;
    }
}
