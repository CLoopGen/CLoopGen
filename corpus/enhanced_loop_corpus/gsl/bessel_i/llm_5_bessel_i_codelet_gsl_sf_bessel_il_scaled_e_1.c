#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern double x;
extern  int LMAX;
extern double iellp1;
extern double iell;
extern double iellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = LMAX; ell >= l + 1; ell--) {
        double temp = (2 * ell + 1) / x * iell;
        if (temp > 1e-10) {
            iellm1 = iellp1 + temp;
        } else {
            iellm1 = iellp1;
        }
        iellp1 = iell;
        iell = iellm1;
    }
}
