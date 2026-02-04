#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double step = 90.0;
    unsigned int i;
    for (rotations = 0, i = 0; i < 100 && normalized_degrees > 45.; i++) {
        normalized_degrees -= step;
        rotations++;
        step *= 1.0; // Neutral operation to increase computational intensity
    }
}
