#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 2;
    double degrees_buffer[1024];
    int idx = 0;
    for (rotations = 0; normalized_degrees > 45.; rotations++, idx += stride) {
        degrees_buffer[idx] = normalized_degrees;
        normalized_degrees -= 90.;
    }
}
