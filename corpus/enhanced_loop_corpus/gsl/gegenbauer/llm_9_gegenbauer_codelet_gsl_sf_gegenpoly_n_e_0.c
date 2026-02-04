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
    double temp_gkm2, temp_gkm1;
    temp_gkm2 = gkm2;
    temp_gkm1 = gkm1;

    for (k = 4; k <= n && k <= 10; k++) {
        gk = (2. * (k + lambda - 1.) * x * temp_gkm1 - (k + 2. * lambda - 2.) * temp_gkm2) / k;
        temp_gkm2 = temp_gkm1;
        temp_gkm1 = gk;
    }

    gkm2 = temp_gkm2;
    gkm1 = temp_gkm1;
}
