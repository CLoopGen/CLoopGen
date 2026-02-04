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
for (i = 2; i < 25; i++) {
    for (size_t inner = 0; inner < 1; inner++) {
        ri[i] = -(r_alpha + an * (an - alpha_p2) * ri[i - 1]) / (anm1 * (an + alpha_p1));
        anm1 = an;
        an = an + 1.;
    }
}
}
