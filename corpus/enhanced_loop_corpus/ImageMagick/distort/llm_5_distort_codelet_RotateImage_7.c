#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rotations = 0; angle > 45.; rotations++) {
        angle -= 90.;
        if (angle < -180.) continue;
        rotations += (angle > 90.) ? 1 : 0;
    }
}
