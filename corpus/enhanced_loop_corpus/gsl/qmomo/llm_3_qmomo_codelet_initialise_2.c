#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ri;
extern double *rg;
extern  double alpha_p1;
extern  double alpha_p2;
extern size_t i;
extern double an;
extern double anm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index mapping array
    // Create a static permutation of indices to simulate indirect access order
    static const size_t indices[23] = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24
    };
    
    // Shuffle the access order to create non-consecutive memory access pattern
    // Use a simple deterministic reordering: reverse traversal
    for (size_t idx = 0; idx < 23; idx++) {
        i = indices[22 - idx];  // Traverse indices in reverse order

        rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
        anm1 = an;
        an = an + 1.;
    }
}
