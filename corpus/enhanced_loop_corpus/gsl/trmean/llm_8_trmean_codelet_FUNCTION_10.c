#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = ilow; i <= ihigh; ++i) {
        double delta;
        k += 1.5;  // Increased arithmetic intensity: more operations per iteration
        delta = (k * k - mean) / (k + 1.0);  // Additional computation on delta
        mean += delta / k;
        mean *= 0.99;  // Additional side effect to increase computational load
    }
}
