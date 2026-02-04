#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce strided memory access with a fixed stride over columns
    // Here, we zero out elements with increasing stride in the column index
    for (j = 1; j <= i__1; j += 2) {  // Stride of 2 in outer loop
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = 0.;
            // Also touch next column if within bounds (simulates wider stride pattern)
            if (j + 1 <= i__1) {
                c__[i__ + (j + 1) * c_dim1] = 0.;
            }
        }
    }
}
