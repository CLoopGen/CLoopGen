#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern  double smooth_threshold;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t j = 0; j < 16; j++) {
        for (ssize_t k = 0; k < 16; k++) {
            ssize_t idx = j * 16 + k;
            if ((second_derivative[idx] < smooth_threshold) && (second_derivative[idx] >= -smooth_threshold))
                second_derivative[idx] = 0.;
        }
    }
}
