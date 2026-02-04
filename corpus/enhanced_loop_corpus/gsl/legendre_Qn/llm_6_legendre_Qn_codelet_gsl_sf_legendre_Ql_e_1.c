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
    double temp_Qellp1 = Qellp1;
    double temp_Qell = Qell;
    for (ell = l; ell > 0; ell--) {
        Qellm1 = (x * (2. * ell + 1.) * temp_Qell - (ell + 1.) * temp_Qellp1) / ell;
        temp_Qellp1 = temp_Qell;
        temp_Qell = Qellm1;
    }
    Qellp1 = temp_Qellp1;
    Qell = temp_Qell;
}
