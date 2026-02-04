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
    double temp1, temp2;
    for (ell = l; ell >= 1; ell--) {
        temp1 = (2.0 * ell + 1.0) / x;
        temp2 = temp1 * iell;
        iellm1 = iellp1 + temp2;
        iellp1 = iell;
        iell = iellm1;
    }
}
