#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *distortion;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i <= 64; i += 2)
        distortion[i] = (1. - distortion[i]) / 2.;
    for (i = 1; i <= 64; i += 2)
        distortion[i] = (1. - distortion[i]) / 2.;
}
