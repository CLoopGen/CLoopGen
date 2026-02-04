#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_angle __attribute__((unused)) = angle;
    size_t local_rotations = 0;
    double update = 90.0;
    for (size_t i = 0; local_angle > 45.; i++) {
        local_angle -= update;
        local_rotations++;
        rotations = local_rotations; // WAW dependency introduced: write-after-write on 'rotations'
    }
    rotations = local_rotations;
}
