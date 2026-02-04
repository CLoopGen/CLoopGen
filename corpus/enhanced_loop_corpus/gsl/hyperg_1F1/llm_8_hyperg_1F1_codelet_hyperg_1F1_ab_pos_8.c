#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and reduced trip count by stepping with increment of 2.0 instead of 1.0
    for (n = a + 1.; n < b - 0.5; n += 2.) {
        double temp1 = (b - n) * Mnm1;
        double temp2 = (2.0 * n - b + x) * Mn;
        double sum = temp1 + temp2;
        Mnp1 = sum / n;
        // Additional floating-point operations to increase compute load
        Mnp1 = (Mnp1 + Mnp1 * 0.1) * (1.0 / (1.0 + 0.1)); // Damped update
        Mnm1 = Mn;
        Mn = Mnp1;
    }
}
