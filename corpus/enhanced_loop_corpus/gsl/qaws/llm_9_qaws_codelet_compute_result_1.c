#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb12;
extern size_t i;
extern double res12;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with combined operations and increased stride
    size_t i;
    for (i = 0; i < 13; i += 3) {
        double temp = r[i] * cheb12[i];
        res12 += temp * temp;  // Square the product to increase arithmetic complexity per iteration
    }
}
