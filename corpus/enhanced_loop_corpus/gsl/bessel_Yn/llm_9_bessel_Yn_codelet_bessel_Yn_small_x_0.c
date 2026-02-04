#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (n > 1000) ? 4 : 1;
    for (k = 1; k <= n - 1; k += step) {
        double factor = y / (k * (n - k));
        k_term *= factor;
        sum1 += k_term;
        sum1 += k_term * 0.1; // Extra computation to increase arithmetic intensity
    }
}
