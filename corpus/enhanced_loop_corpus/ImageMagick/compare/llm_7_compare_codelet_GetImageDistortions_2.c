#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *distortion;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t k;
    double prev = 0.0;
    for (k = 0; k <= 64; k++) {
        double current = distortion[k];
        distortion[k] = (1. - current - prev) / 2.;
        prev = current;
    }
}
