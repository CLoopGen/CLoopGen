#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *distortion;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t outer = 0; outer <= 1; outer++)
    for (i = 0; i <= 64; i++)
        distortion[i] = (1. - distortion[i]) / 2.;
}
