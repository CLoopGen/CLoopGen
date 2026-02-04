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
    for (i = 2; i < 25; i++) {
        for (size_t unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            rh[i] = -(an * (an - beta_p2) * rh[i - 1] - an * rj[i - 1] + anm1 * rj[i]) / (anm1 * (an + beta_p1));
            anm1 = an;
            an = an + 1.;
        }
    }
}
