#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *covariance;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.F;
    for (i = 0; i < 6; i++) {
        temp += covariance[i];
        covariance[i] = temp;
        temp -= covariance[i];
    }
}
