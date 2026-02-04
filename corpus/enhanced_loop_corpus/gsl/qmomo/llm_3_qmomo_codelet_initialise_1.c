#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern  double beta_p1;
extern  double beta_p2;
extern  double r_beta;
extern size_t i;
extern double an;
extern double anm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    size_t indices[24];
    for (size_t j = 0; j < 24; j++) {
        indices[j] = 2 + (j * 3) % 23; // Pseudo-randomized but deterministic order within bounds
    }
    for (i = 0; i < 24; i++) {
        size_t idx = indices[i];
        if (idx >= 2) {
            rj[idx] = -(r_beta + an * (an - beta_p2) * rj[idx - 1]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.0;
        }
    }
}
