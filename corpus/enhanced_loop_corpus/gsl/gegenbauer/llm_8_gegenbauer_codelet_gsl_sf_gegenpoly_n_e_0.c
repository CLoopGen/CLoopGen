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
    int k_start = (n >= 8) ? 8 : 4;
    for (k = k_start; k <= n; k += 2) {
        gk = (2. * (k + lambda - 1.) * x * gkm1 - (k + 2. * lambda - 2.) * gkm2) / k;
        gkm2 = gkm1;
        gkm1 = gk;

        if (k + 1 <= n) {
            k++;
            gk = (2. * (k + lambda - 1.) * x * gkm1 - (k + 2. * lambda - 2.) * gkm2) / k;
            gkm2 = gkm1;
            gkm1 = gk;
        }
    }
}
