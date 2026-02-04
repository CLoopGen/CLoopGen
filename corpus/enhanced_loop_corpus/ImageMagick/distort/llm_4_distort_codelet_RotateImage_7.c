#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rotations = 0; angle > 45. && rotations < 1000; rotations++) {
        if (angle <= 0.) break;
        angle -= 90.;
    }
}
