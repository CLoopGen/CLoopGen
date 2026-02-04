#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double threshold_squared = smooth_threshold * smooth_threshold;
    for (i = 0; i <= 255; i++) {
        double val = second_derivative[i];
        double val_squared = val * val;
        if (val_squared < threshold_squared)
            second_derivative[i] = 0.;
    }
}
