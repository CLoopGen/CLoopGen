#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rotations = 0;
    double temp_degrees = normalized_degrees;
    double *degrees_ptr = &temp_degrees;
    for (rotations = 0; *degrees_ptr > 45.; rotations++) {
        *degrees_ptr -= 90.;
    }
    rotations = temp_rotations;
}
