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
for (ell = 1; ell < l; ell++) {
    if (ell % 2 == 0) {
        Qellp1 = (x * (2. * ell + 1.) * Qell - ell * Qellm1) / (ell + 1.);
    } else {
        Qellp1 = (x * (2. * ell - 1.) * Qell - (ell - 1) * Qellm1) / ell;
    }
    Qellm1 = Qell;
    Qell = Qellp1;
}
}
