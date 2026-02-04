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
    if (n < 4) return;
    for (k = 4; k <= n; k++) {
        if (k % 2 == 0) {
            gk = (2. * (k + lambda - 1.) * x * gkm1 - (k + 2. * lambda - 2.) * gkm2) / k;
        } else {
            gk = (2. * (k + lambda - 0.5) * x * gkm1 - (k + 2. * lambda - 3.) * gkm2) / k;
        }
        gkm2 = gkm1;
        gkm1 = gk;
    }
}
