#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal and stride simulation
    // We reverse the inner loop and access elements with explicit striding behavior
    // to simulate non-unit stride patterns that might occur in blocked algorithms.
    integer stride = c_dim1;
    for (j = i__1; j >= 1; --j) {
        for (i__ = *n; i__ >= j; --i__) {
            c__[i__ * stride + j] = 0.;  // Note: Using j as row index creates a different access pattern
        }
    }
}
