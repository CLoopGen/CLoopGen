#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 255; i++) {
    double val = second_derivative[i];
    if (val >= smooth_threshold || val < -smooth_threshold)
        continue;
    second_derivative[i] = 0.;
}
}
