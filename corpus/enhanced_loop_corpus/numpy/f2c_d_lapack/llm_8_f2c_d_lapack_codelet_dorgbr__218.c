#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling inner loop and increasing arithmetic operations
    for (j = 2; j <= i__1; ++j) {
        for (i__ = j - 1; i__ >= 3; i__ -= 2) {
            // Unroll two iterations: perform two assignments per loop iteration
            a[i__ + j * a_dim1] = a[i__ - 1 + j * a_dim1] + 1.0;
            a[i__ - 1 + j * a_dim1] = a[i__ - 2 + j * a_dim1] + 1.0;
        }
        // Handle remaining element if any
        if (i__ == 2) {
            a[i__ + j * a_dim1] = a[i__ - 1 + j * a_dim1] + 1.0;
        }
        a[j * a_dim1 + 1] = 0.;
    }
}
