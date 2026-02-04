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
    // Variant 1: Strided Memory Access (access every 2nd element, unrolled-like pattern)
    // We simulate a strided access by stepping through the array with a stride of 2
    // Adjust loop bounds accordingly to stay within valid range
    for (i = 2; i < 24; i += 2) {
        size_t next_i = i + 1;
        // Compute current and next index values if within bounds
        rh[i] = -(an * (an - beta_p2) * rh[i - 1] - an * rj[i - 1] + anm1 * rj[i]) / (anm1 * (an + beta_p1));
        anm1 = an;
        an = an + 1.;

        if (next_i < 25) {
            rh[next_i] = -(an * (an - beta_p2) * rh[next_i - 1] - an * rj[next_i - 1] + anm1 * rj[next_i]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.;
        }
    }
}
