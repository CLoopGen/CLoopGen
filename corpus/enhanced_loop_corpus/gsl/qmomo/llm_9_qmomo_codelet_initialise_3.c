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
for (i = 2; i < 25; i += 2) { // Increase step size to reduce trip count
    double temp_rh = -(an * (an - beta_p2) * rh[i - 1] - an * rj[i - 1] + anm1 * rj[i]) / (anm1 * (an + beta_p1));
    rh[i] = temp_rh;
    rh[i-1] = temp_rh; // Duplicate computation across two indices
    anm1 = an;
    an = an + 2.; // Match step in induction variable
}
}
