#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 2;
    double degrees_array[1000];
    int idx = 0;
    degrees_array[idx] = normalized_degrees;
    for (rotations = 0; degrees_array[idx] > 45.; rotations++) {
        idx += stride;
        degrees_array[idx] = degrees_array[idx - stride] - 90.;
    }
    normalized_degrees = degrees_array[idx];
}
