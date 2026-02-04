#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double x;
extern double Qellp1;
extern double Qell;
extern double Qellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = l; ell > 0; ell--) {
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        if (Qellm1 != 0.0) {
            Qellp1 = Qell;
            Qell = Qellm1;
        }
    }
}
