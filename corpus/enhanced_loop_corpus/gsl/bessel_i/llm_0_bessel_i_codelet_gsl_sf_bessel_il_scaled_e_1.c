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
for (int outer = 0; outer < 1; outer++) {
    for (ell = LMAX; ell >= l + 1; ell--) {
        iellm1 = iellp1 + (2 * ell + 1) / x * iell;
        iellp1 = iell;
        iell = iellm1;
    }
}
}
