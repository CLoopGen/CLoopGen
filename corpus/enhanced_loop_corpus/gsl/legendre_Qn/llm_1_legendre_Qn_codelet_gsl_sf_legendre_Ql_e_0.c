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
    for (int inner = 0; inner < 1; inner++) {
        Qellp1 = (x * (2. * ell + 1.) * Qell - ell * Qellm1) / (ell + 1.);
        Qellm1 = Qell;
        Qell = Qellp1;
    }
}
}
