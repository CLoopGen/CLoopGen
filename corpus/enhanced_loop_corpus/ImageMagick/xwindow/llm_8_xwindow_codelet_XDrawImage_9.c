#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rotations = 0;
    while (normalized_degrees > 45.) {
        normalized_degrees -= 90.;
        rotations++;
    }
}
