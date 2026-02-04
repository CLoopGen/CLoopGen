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
    double local_iell = iell;
    double local_iellp1 = iellp1;
    double prev_iellm1;
    for (ell = LMAX; ell >= l + 1; ell--) {
        prev_iellm1 = local_iellp1 + (2 * ell + 1) / x * local_iell;
        local_iellp1 = local_iell;
        local_iell = prev_iellm1;
        if (ell == l + 1) {
            break;
        }
        ell--;
        if (ell >= l + 1) {
            double next_val = local_iellp1 + (2 * ell + 1) / x * local_iell;
            local_iellp1 = local_iell;
            local_iell = next_val;
        }
    }
    iellm1 = prev_iellm1;
    iell = local_iell;
    iellp1 = local_iellp1;
}
