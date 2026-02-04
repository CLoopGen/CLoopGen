#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing diagonal elements (i,i), access every second element along the diagonal
    // This creates a strided access pattern with stride = a_dim1 + 1, but skipping every other element
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        a[i__ + i__ * a_dim1] = *beta;
    }
}
