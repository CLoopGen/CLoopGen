#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double x;
extern double Qellm1;
extern double Qell;
extern double Qellp1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ell = 2; ell < l + (l >> 1); ell++) {
    double coeff1 = x * (2. * ell + 1.);
    double coeff2 = ell;
    double coeff3 = 1.0 / (ell + 1.);
    Qellp1 = (coeff1 * Qell - coeff2 * Qellm1) * coeff3;
    Qellm1 = Qell;
    Qell = Qellp1;
}
}
