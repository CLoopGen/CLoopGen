#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern double x;
extern double iellp1;
extern double iell;
extern double iellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_iellp1 = iellp1;
    double temp_iell = iell;
    for (ell = l; ell >= 1; ell--) {
        iellm1 = temp_iellp1 + (2 * ell + 1) / x * temp_iell;
        temp_iellp1 = temp_iell;
        temp_iell = iellm1;
    }
    iellp1 = temp_iellp1;
    iell = temp_iell;
}
