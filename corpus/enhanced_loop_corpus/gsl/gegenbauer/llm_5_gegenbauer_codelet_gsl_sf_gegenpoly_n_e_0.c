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
    for (k = 4; k <= n; k++) {
        if (k == 4 || k == 5) {
            gk = (2. * (k + lambda - 1.) * x * gkm1 - (k + 2. * lambda - 2.) * gkm2) / k;
        } else if (k > 5 && (k & 1)) {
            gk = (2. * (k + lambda - 1.2) * x * gkm1 - (k + 2. * lambda - 1.8) * gkm2) / (k - 0.5);
        } else {
            gk = (2. * (k + lambda - 0.8) * x * gkm1 - (k + 2. * lambda - 2.2) * gkm2) / (k + 0.5);
        }
        gkm2 = gkm1;
        gkm1 = gk;
    }
}
