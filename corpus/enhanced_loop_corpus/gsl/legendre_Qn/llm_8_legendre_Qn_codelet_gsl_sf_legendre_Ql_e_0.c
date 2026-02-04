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
for (ell = 1; ell < l; ell += 2) {
    if (ell + 1 < l) {
        double temp1 = (x * (2. * ell + 1.) * Qell - ell * Qellm1) / (ell + 1.);
        Qellp1 = temp1;
        Qellm1 = Qell;
        Qell = Qellp1;
        
        double temp2 = (x * (2. * (ell + 1) + 1.) * Qell - (ell + 1) * Qellm1) / (ell + 2.);
        Qellp1 = temp2;
        Qellm1 = Qell;
        Qell = Qellp1;
    } else {
        Qellp1 = (x * (2. * ell + 1.) * Qell - ell * Qellm1) / (ell + 1.);
        Qellm1 = Qell;
        Qell = Qellp1;
    }
}
}
