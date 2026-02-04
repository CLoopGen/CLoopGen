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
    // Variant 1: Strided memory access (access every 2nd element in a staggered manner)
    for (i = 2; i < 25; i += 2) {
        size_t idx = i;
        if (idx + 1 < 25) {
            // Process two elements with stride of 2 to alter access pattern
            rj[idx] = -(r_beta + an * (an - beta_p2) * rj[idx - 1]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.0;

            rj[idx + 1] = -(r_beta + an * (an - beta_p2) * rj[idx]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.0;
        } else {
            rj[idx] = -(r_beta + an * (an - beta_p2) * rj[idx - 1]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.0;
        }
    }
}
