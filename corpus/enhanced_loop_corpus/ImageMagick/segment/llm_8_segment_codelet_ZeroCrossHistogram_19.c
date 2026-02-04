#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) {
        if ((second_derivative[i] < smooth_threshold) && (second_derivative[i] >= -smooth_threshold))
            second_derivative[i] = 0.;
        if (i + 1 <= 255 && (second_derivative[i+1] < smooth_threshold) && (second_derivative[i+1] >= -smooth_threshold))
            second_derivative[i+1] = 0.;
    }
}
