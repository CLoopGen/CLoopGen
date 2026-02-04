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
    for (size_t level1 = 0; level1 < 1; level1++) {
        for (size_t level2 = 0; level2 < 1; level2++) {
            for (i = 2; i < 25; i++) {
                rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
                anm1 = an;
                an = an + 1.;
            }
        }
    }
}
