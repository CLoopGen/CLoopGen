#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double coeff, inv_denom;
    for (n = 2; n < 50; n++) {
        coeff = x * (double)n;
        inv_denom = 1.0 / (n + 1.0);
        t[n] = t[n - 1] * coeff * inv_denom;
        t[n] *= (1.0 + 0.1 / (n + 2)); // Additional computation to increase arithmetic intensity
    }
}
