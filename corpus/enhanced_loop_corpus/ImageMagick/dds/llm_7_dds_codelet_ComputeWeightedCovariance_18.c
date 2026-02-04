#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *covariance;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = 0.F;
    for (i = 0; i < 6; i++) {
        float current = covariance[i];
        covariance[i] = prev;
        prev = current;
    }
    covariance[0] = prev;
}
