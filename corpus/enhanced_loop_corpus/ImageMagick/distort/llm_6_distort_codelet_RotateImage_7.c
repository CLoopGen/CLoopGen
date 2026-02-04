#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_angle = angle;
    for (rotations = 0; temp_angle > 45.; rotations++) {
        temp_angle -= 90.;
    }
    angle = temp_angle;
}
