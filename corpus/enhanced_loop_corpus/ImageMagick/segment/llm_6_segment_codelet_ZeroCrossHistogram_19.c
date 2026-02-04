#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i <= 255; i++) {
        temp = second_derivative[i];
        if ((temp < smooth_threshold) && (temp >= -smooth_threshold)) {
            second_derivative[i] = 0.;
        }
    }
}
