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
    double temp_rj;
    for (i = 2; i < 25; i++) {
        temp_rj = -(r_beta + an * (an - beta_p2) * rj[i - 1]) / (anm1 * (an + beta_p1));
        anm1 = an;
        an = an + 1.;
        rj[i] = temp_rj;
    }
}
