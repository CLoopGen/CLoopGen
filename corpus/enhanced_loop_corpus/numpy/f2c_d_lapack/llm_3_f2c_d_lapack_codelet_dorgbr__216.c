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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 3 (access every third element)
    integer stride = 3;
    integer remainder = (2 - 1) % stride;
    i__ = 2 + (remainder ? stride - remainder : 0); // Adjust starting index to align with stride pattern
    for (; i__ <= i__1; i__ += stride) {
        a[i__ + a_dim1] = 0.;
    }
}
