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
for (i = 2; i < 25; i++) {
    double temp_denom = anm1 * (an + alpha_p1);
    if (temp_denom != 0.0) {
        rg[i] = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / temp_denom;
    } else {
        rg[i] = 0.0;
    }
    anm1 = an;
    an = an + 1.;
    if (an > 30.0) break;
}
}
