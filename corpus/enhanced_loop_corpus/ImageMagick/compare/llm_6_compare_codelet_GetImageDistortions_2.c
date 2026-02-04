#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *distortion;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    double temp;
    for (j = 0; j <= 64; j++) {
        temp = distortion[j];
        distortion[j] = (1. - temp) / 2.;
    }
}
