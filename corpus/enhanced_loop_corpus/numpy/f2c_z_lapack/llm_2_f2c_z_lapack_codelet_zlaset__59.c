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

extern doublecomplex *beta;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing diagonal elements (i,i), access elements with a stride of (a_dim1 + 2)
    // This creates a strided access pattern across the 2D array 'a' interpreted in row-major order
    integer stride = a_dim1 + 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = 1 + (i__ - 1) * stride;  // Linearized index with custom stride
        if (i__2 < (a_dim1 + 1) * (i__1 + 1)) {  // Simple bounds check to stay within allocated range
            a[i__2].r = beta->r;
            a[i__2].i = beta->i;
        }
    }
}
