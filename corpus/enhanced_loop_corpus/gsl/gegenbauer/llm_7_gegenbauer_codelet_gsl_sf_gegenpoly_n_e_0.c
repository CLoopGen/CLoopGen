#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double lambda;
extern double x;
extern int k;
extern double gkm2;
extern double gkm1;
extern double gk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_gkm2 = gkm2, prev_gkm1 = gkm1;
    for (k = 4; k <= n; k++) {
        double new_gk = (2. * (k + lambda - 1.) * x * prev_gkm1 - (k + 2. * lambda - 2.) * prev_gkm2) / k;
        if (k > 4) {
            gk = new_gk; // Write updated value earlier, but not used in this iteration
        }
        prev_gkm2 = prev_gkm1;
        prev_gkm1 = new_gk;
    }
    // Final update to global state after loop
    if (n >= 4) {
        gk = (2. * (n + lambda - 1.) * x * prev_gkm1 - (n + 2. * lambda - 2.) * prev_gkm2) / n;
        gkm1 = prev_gkm1;
        gkm2 = prev_gkm2;
    }
}
