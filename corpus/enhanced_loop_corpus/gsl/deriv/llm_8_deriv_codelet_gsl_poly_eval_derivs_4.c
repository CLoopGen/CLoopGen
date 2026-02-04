#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  size_t lenc;
extern double res[];
extern  size_t lenres;
extern size_t i;
extern size_t n;
extern size_t nmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, n = 0, nmax = 0; i < lenres; i++) {
        if (n < lenc) {
            res[i] = c[lenc - 1] * c[lenc - 1] + 1e-8; // Increased arithmetic intensity: square and add
            nmax = n + (n & 1); // More complex update to nmax
            n += 2; // Increase step size to reduce effective iterations over c
            if (n >= lenc) n = lenc; // Clamp to prevent overflow
        } else {
            res[i] = 0.0;
        }
    }
}
