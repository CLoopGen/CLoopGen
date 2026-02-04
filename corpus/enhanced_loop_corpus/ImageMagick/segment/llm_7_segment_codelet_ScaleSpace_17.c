#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *gamma;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    for (x = 0; x <= 255; x++) {
        gamma[x] = prev;
        prev = gamma[x] + 1.0;
    }
}
