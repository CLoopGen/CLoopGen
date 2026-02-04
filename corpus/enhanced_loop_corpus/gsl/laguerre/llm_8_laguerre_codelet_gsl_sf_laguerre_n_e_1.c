#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern  double x;
extern double Lkm1;
extern double Lk;
extern double Lkp1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 2; k < n && n > 2; k += 2) {
        double temp1, temp2;
        // First iteration step
        temp1 = (-(k + a) * Lkm1 + (2. * k + a + 1. - x) * Lk) / (k + 1.);
        // Second iteration step unrolled
        temp2 = (-(k + 1. + a) * Lk + (2.*(k+1.) + a + 1. - x) * temp1) / (k + 2.);
        // Update state variables for two steps
        Lkm1 = temp1;
        Lk = temp2;
    }
    // Handle odd n case if needed
    if ((n - 2) % 2 == 1 && k - 1 < n) {
        Lkp1 = (-(k + a) * Lkm1 + (2. * k + a + 1. - x) * Lk) / (k + 1.);
        Lkm1 = Lk;
        Lk = Lkp1;
    }
}
