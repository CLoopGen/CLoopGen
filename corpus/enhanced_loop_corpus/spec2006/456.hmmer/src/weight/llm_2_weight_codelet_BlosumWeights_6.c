#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing c[0], c[1], ..., access every 2nd element forward and backward to create strided access.
    // We simulate a strided read on array c, updating nmem accordingly.
    int stride = 2;
    int limit = nseq - (nseq % stride); // Make sure we don't go out of bounds

    for (i = 0; i < limit; i += stride) {
        nmem[c[i]]++;
        if (i + 1 < nseq) {
            nmem[c[i + 1]]++;
        }
    }

    // Handle any remaining elements if nseq is not divisible by stride
    for (i = limit; i < nseq; i++) {
        nmem[c[i]]++;
    }
}
