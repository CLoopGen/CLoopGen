#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern double qq;
extern double aa;
extern int nterms;
extern double term1;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using index scaling
    // Here we simulate a strided traversal by modifying the effective index used in computation
    // Although no array is present, we modify the access pattern to nterms via stride
    int stride = 2;
    for (ii = 0; ii < nterms; ii += stride) {
        int idx = ii; // Logical index still used, but loop progresses with stride
        term1 = qq * qq / (aa - (order + 2. * (nterms - idx)) * (order + 2. * (nterms - idx)) - term1);
        // Ensure progress by updating term1 even with stride
        if (ii + 1 < nterms) {
            int next_idx = ii + 1;
            term1 = qq * qq / (aa - (order + 2. * (nterms - next_idx)) * (order + 2. * (nterms - next_idx)) - term1);
        }
    }
}
