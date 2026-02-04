#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double x;
extern double Jkp1;
extern double Jk;
extern double Jkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Trip count remains the same, but each iteration performs more work
    for (k = n; k > 0; k--) {
        double temp1 = 2. * k / x * Jk;
        double temp2 = temp1 - Jkp1;
        Jkm1 = temp2 + (temp1 * Jk) / (x + 1.);  // Additional computation to increase intensity
        Jkp1 = Jk + 0.1 * Jkm1;  // Slight perturbation introduced
        Jk = Jkm1 - 0.05 * Jkp1;
    }
}
