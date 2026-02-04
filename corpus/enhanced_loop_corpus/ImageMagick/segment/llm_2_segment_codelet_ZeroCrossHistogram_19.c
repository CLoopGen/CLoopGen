#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    ssize_t stride = 2;
    for (i = 0; i <= 255; i += stride) {
        if ((second_derivative[i] < smooth_threshold) && (second_derivative[i] >= -smooth_threshold))
            second_derivative[i] = 0.;
    }
    for (i = 1; i <= 255; i += stride) {
        if ((second_derivative[i] < smooth_threshold) && (second_derivative[i] >= -smooth_threshold))
            second_derivative[i] = 0.;
    }
}
