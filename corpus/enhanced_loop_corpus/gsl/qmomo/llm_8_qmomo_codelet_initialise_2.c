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
for (i = 2; i < 50; i++) {
    rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
    rg[i] += (an > 5.0) ? (rg[i] * 0.1 - ri[i-2]) : 0.0;
    anm1 = an;
    an = an + 1.;
}
}
