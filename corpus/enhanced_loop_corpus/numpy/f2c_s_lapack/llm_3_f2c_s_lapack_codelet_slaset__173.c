#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride across the array, skipping elements periodically
    // This variant writes every 2nd row starting from row j+1, creating a strided pattern in memory
    integer stride = 2;
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = j + 1; i__ <= i__2; i__ += stride) { // Stride of 2 in the i__ index
            a[i__ + j * a_dim1] = *alpha;
        }
    }
}
