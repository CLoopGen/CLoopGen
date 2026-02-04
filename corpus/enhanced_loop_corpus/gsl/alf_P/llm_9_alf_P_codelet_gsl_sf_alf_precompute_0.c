#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern double *alm;
extern size_t l;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 2; l <= lmax; l += 2) {
        double inv_l = 1.0 / (double)l;
        double term1 = 2.0 - inv_l;
        double term2 = -(1.0 - inv_l);
        alm[2 * k] = term1;
        alm[2 * k + 1] = term2;

        if (l + 1 <= lmax) {
            double inv_lp1 = 1.0 / (double)(l + 1);
            alm[2 * (k + 1)] = 2.0 - inv_lp1;
            alm[2 * (k + 1) + 1] = -(1.0 - inv_lp1);
        }
        k++;
    }
}
