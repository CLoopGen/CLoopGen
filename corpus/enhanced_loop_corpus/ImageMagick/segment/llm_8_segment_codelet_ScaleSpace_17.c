#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *gamma;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= 511; x += 2) {
        gamma[x] = 0.;
        if (x + 1 <= 255)
            gamma[x + 1] = 0.;
    }
}
