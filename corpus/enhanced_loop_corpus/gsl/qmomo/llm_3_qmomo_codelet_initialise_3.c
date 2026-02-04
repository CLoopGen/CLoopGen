#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern  double beta_p1;
extern  double beta_p2;
extern size_t i;
extern double an;
extern double anm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping Array
    // Use a precomputed index map to access array elements in a non-sequential order
    // This simulates irregular or data-dependent access patterns
    static const size_t index_map[23] = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24
    }; // Identity map for clarity, but structure allows arbitrary reordering

    for (i = 0; i < 23; i++) {
        size_t idx = index_map[i];  // Current index accessed indirectly
        rh[idx] = -(an * (an - beta_p2) * rh[idx - 1] - an * rj[idx - 1] + anm1 * rj[idx]) / (anm1 * (an + beta_p1));
        anm1 = an;
        an = an + 1.;
    }
}
