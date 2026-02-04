#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *ihi;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use base pointers and stride manually to simulate strided access
    // We step through the array using incremented pointers instead of index calculations
    real *base_a = a;
    integer stride = a_dim1;
    integer j_start = *ihi + 1;

    for (j = j_start; j <= i__1; ++j) {
        real *row_start = base_a + j * stride;
        for (i__ = 1; i__ <= *n; ++i__) {
            *(row_start + i__) = 0.F;  // Equivalent to a[i__ + j*a_dim1]
        }
        *(row_start + j) = 1.F;  // Set diagonal element
    }
}
