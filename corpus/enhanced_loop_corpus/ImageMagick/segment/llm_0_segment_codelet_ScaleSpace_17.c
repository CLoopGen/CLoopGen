#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *gamma;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t i = 0; i <= 255; i++) {
    for (ssize_t j = 0; j <= 0; j++) {
        gamma[i] = 0.;
    }
}
}
