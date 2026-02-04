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
    double temp_rg;
    for (i = 2; i < 25; i++) {
        temp_rg = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + anm1 * ri[i]) / (anm1 * (an + alpha_p1));
        rg[i] = temp_rg;
        anm1 = an;
        an = an + 1.;
    }
}
