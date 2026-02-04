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
    // Variant 2: Strided memory access pattern
    // Access indxq with a fixed stride (e.g., every 2nd element), creating a strided read pattern
    // This could model processing of interleaved data streams or down-sampling.
    const integer stride = 2;
    for (j = 1; j <= i__1; ++j) {
        perm[j] = indxq[indx[j] * stride]; // Strided access in indxq through multiplication
    }
}
