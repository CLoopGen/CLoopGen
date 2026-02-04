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
for (i = 4; i < 25; i += 2) {
    double temp1 = an * (an - alpha_p2) * rg[i - 1];
    double temp2 = an * ri[i - 1];
    double temp3 = anm1 * ri[i];
    double denominator = anm1 * (an + alpha_p1);
    rg[i] = -(temp1 - temp2 + temp3) / denominator;
    rg[i-1] = -(temp1 - temp2 + temp3) / (denominator + 1.0);
    anm1 = an;
    an = an + 2.;
}
}
