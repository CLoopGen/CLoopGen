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
    double prev_an = anm1;
    for (i = 2; i < 25; i++) {
        double computed_val = -(an * (an - alpha_p2) * rg[i - 1] - an * ri[i - 1] + prev_an * ri[i]) / (prev_an * (an + alpha_p1));
        rg[i] = computed_val;
        prev_an = an;
        an = an + 1.;
    }
}
