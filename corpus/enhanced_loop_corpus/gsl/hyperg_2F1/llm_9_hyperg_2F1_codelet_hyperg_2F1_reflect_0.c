#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern  double ad;
extern double d2;
extern int i;
extern double sum1;
extern double term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified operations
    for (i = 0; i < ad * 2; i++) {
        int j = (i >> 1);  // Equivalent to floor(i/2), replaces i-1 in original logic
        double factor = (1. - x);
        if (i % 2 == 1) {
            term *= (a + d2 + j) * (b + d2 + j) / (1. + d2 + j + 1e-9) * factor;
            sum1 += term;
        }
    }
}
