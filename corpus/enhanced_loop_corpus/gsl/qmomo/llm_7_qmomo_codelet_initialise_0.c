#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ri;
extern  double alpha_p1;
extern  double alpha_p2;
extern  double r_alpha;
extern size_t i;
extern double an;
extern double anm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_anm1 = anm1;
    for (i = 2; i < 25; i++) {
        double computed_val = -(r_alpha + an * (an - alpha_p2) * ri[i - 1]) / (prev_anm1 * (an + alpha_p1));
        ri[i] = computed_val;
        prev_anm1 = an;
        an = an + 1.;
    }
}
