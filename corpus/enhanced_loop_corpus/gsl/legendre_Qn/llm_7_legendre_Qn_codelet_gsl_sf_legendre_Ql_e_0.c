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
    double prev_Qellm1 = Qellm1;
    double prev_Qell = Qell;
    for (ell = 1; ell < l; ell++) {
        if (ell == 1) {
            Qellp1 = (x * (2. * ell + 1.) * prev_Qell - ell * prev_Qellm1) / (ell + 1.);
        } else {
            Qellp1 = (x * (2. * ell + 1.) * Qell - ell * Qellm1) / (ell + 1.);
        }
        Qellm1 = prev_Qell;
        Qell = Qellp1;
        prev_Qell = Qell;
        prev_Qellm1 = Qellm1;
    }
}
