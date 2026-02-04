#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_degrees = normalized_degrees;
    for (rotations = 0; temp_degrees > 45.; rotations++) {
        temp_degrees -= 90.;
    }
    normalized_degrees = temp_degrees;
}
