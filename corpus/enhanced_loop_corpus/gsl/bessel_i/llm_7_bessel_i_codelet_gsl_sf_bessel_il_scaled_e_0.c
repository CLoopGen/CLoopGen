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
    double prev_iell = iell;
    double prev_iellp1 = iellp1;
    double new_iell, new_iellp1;
    for (ell = l; ell >= 1; ell--) {
        new_iell = prev_iellp1 + (2 * ell + 1) / x * prev_iell;
        new_iellp1 = prev_iell;
        prev_iell = new_iell;
        prev_iellp1 = new_iellp1;
    }
    iell = new_iell;
    iellp1 = new_iellp1;
}
