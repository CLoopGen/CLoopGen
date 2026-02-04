#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *cumulative_histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, then fill in)
    for (ssize_t stride = 2; stride >= 1; stride--) {
        for (i = stride; i <= 255; i += stride) {
            if (i >= 1) {
                cumulative_histogram[i] = cumulative_histogram[i - 1] + histogram[i];
            }
        }
    }
}
