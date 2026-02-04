#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  int m;
extern  double x;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double next_p_ellm2, next_p_ellm1;
    next_p_ellm2 = p_ellm2;
    next_p_ellm1 = p_ellm1;
    for (ell = m + 2; ell <= l; ell++) {
        double p_curr = (x * (2 * ell - 1) * next_p_ellm1 - (ell + m - 1) * next_p_ellm2) / (ell - m);
        if (ell >= m + 3) {
            p_ellm2 = next_p_ellm1;
        }
        next_p_ellm2 = next_p_ellm1;
        next_p_ellm1 = p_curr;
        if (ell == l) {
            p_ell = p_curr;
            p_ellm1 = p_curr;
        }
    }
}
