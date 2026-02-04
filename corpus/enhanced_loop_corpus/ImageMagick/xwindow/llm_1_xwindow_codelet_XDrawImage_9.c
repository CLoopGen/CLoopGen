#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rotations = 0;
    if (normalized_degrees > 45.) {
        for (int outer = 0; outer < 1000 && normalized_degrees > 45.; outer++) {
            normalized_degrees -= 90.;
            rotations++;
        }
    }
}
