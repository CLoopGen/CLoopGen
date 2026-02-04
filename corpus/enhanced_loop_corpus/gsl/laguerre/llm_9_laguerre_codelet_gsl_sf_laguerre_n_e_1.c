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
    double sum_reduction = 0.0;
    int stride = 4;
    // Increase computational intensity via multiple accumulations and trip count reduction
    for (k = 2; k + stride - 1 < n; k += stride) {
        double Lkp1_1, Lkp1_2, Lkp1_3, Lkp1_4;
        // Step 1
        Lkp1_1 = (-(k + a) * Lkm1 + (2. * k + a + 1. - x) * Lk) / (k + 1.);
        sum_reduction += Lkp1_1 * Lkp1_1;
        // Step 2
        Lkp1_2 = (-(k+1. + a) * Lk + (2.*(k+1.) + a + 1. - x) * Lkp1_1) / (k + 2.);
        sum_reduction += Lkp1_2 * Lkp1_2;
        // Step 3
        Lkp1_3 = (-(k+2. + a) * Lkp1_1 + (2.*(k+2.) + a + 1. - x) * Lkp1_2) / (k + 3.);
        sum_reduction += Lkp1_3 * Lkp1_3;
        // Step 4
        Lkp1_4 = (-(k+3. + a) * Lkp1_2 + (2.*(k+3.) + a + 1. - x) * Lkp1_3) / (k + 4.);
        sum_reduction += Lkp1_4 * Lkp1_4;

        // Update state to last computed value
        Lkm1 = Lkp1_3;
        Lk = Lkp1_4;
    }
    // Tail loop for remaining elements
    for (; k < n; k++) {
        Lkp1 = (-(k + a) * Lkm1 + (2. * k + a + 1. - x) * Lk) / (k + 1.);
        Lkm1 = Lk;
        Lk = Lkp1;
    }
    // Prevent unused variable elimination
    if (sum_reduction < 0) {
        Lk += sum_reduction;
    }
}
