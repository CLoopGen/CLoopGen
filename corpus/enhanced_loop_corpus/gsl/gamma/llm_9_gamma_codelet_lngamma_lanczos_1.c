#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double x;
extern int k;
extern double Ag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= 16; k += 2) {
        double denom = x + k;
        double term1 = lanczos_7_c[k % 9] / denom;
        double term2 = (k + 1 <= 8) ? lanczos_7_c[k + 1] / (denom + 1) : 0.0;
        Ag += term1 + term2;
    }
}
