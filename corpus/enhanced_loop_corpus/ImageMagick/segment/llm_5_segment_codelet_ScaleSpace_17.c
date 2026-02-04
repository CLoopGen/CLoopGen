#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *gamma;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= 255; x++) {
        if (x >= 64 && x < 192) {
            continue;
        }
        gamma[x] = 0.;
    }
}
