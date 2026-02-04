#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rotations = 0; angle > 45.; rotations++) {
        if (angle <= 135.0) {
            angle -= 90.;
        } else {
            for (size_t i = 0; i < 2; i++) {
                angle -= 45.;
            }
        }
    }
}
