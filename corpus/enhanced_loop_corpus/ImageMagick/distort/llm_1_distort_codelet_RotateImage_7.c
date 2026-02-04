#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rotations = 0; angle > 45.; rotations += 2) {
        angle -= 90.;
        if (angle <= 45.) break;
        rotations++;
        angle -= 90.;
    }
}
