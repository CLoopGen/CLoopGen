#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *covariance;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < 12; i += 2) {
        covariance[i] = 0.F;
        if (i + 1 < 12) {
            covariance[i + 1] = 0.F;
        }
    }
}
