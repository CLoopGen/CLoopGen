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
    double prev_an = anm1;
    double current_an = an;
    for (i = 2; i < 25; i++) {
        rj[i] = -(r_beta + current_an * (current_an - beta_p2) * rj[i - 1]) / (prev_an * (current_an + beta_p1));
        prev_an = current_an;
        current_an += 1.0;
    }
    anm1 = prev_an;
    an = current_an;
}
