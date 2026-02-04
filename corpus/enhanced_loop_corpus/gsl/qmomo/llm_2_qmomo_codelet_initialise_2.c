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
    // Variant 1: Strided Memory Access (access every 2nd element, unrolled-like pattern)
    // We simulate a strided access by stepping by 2 and adjusting dependencies accordingly.
    // Since original loop starts at i=2, we start at i=2 and step by 2, ensuring bounds are respected.
    for (i = 2; i < 25; i += 2) {
        if (i + 1 < 25) {
            // Compute current index
            rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
            anm1 = an;
            an = an + 1.;

            // Compute next index manually without incrementing loop variable twice
            size_t j = i + 1;
            rg[j] = -(an * (an - alpha_p2) * rg[j - 1] - an * ri[j - 1] + anm1 * ri[j]) / (anm1 * (an + alpha_p1));
            anm1 = an;
            an = an + 1.;
        } else {
            // Handle odd-sized tail if needed (though 25-2=23 is odd, so last i=24 will be handled above)
            rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
            anm1 = an;
            an = an + 1.;
        }
    }
}
