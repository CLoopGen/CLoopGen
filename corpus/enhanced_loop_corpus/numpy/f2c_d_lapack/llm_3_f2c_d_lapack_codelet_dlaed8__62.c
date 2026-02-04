#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *perm;
extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on indxq with reversed traversal and stride of 2 (with wrap-around logic)
    // Simulate strided access by stepping through j in reverse with a fixed stride pattern
    // This changes spatial locality and access order, creating non-unit stride behavior
    integer stride = 2;
    integer count = (i__1 + stride - 1) / stride;  // Number of iterations needed
    for (integer k = 0; k < count; ++k) {
        j = i__1 - k * stride;  // Reverse strided index
        if (j >= 1) {
            perm[j] = indxq[indx[j]];
        }
        integer j2 = j - 1;
        if (j2 >= 1) {
            perm[j2] = indxq[indx[j2]];
        }
    }
}
