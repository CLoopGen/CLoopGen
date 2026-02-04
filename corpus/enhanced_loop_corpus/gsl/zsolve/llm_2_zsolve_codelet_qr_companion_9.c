#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the index calculation
    // Instead of accessing diagonal elements (i-1)*(nc+1), we traverse consecutive locations
    // This changes semantics but demonstrates a pattern shift to sequential access
    size_t idx = 0;
    for (i = 1; i <= n; i++) {
        ((h)[idx]) -= x;
        idx += (nc + 1); // Stride remains, but computed outside subscript
    }
}
