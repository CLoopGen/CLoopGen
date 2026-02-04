#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_accumulator = 0.0;
    unsigned int i;
    for (i = 0; normalized_degrees - local_accumulator > 45.; i++) {
        local_accumulator += 90.;
    }
    rotations = i;
    normalized_degrees -= local_accumulator;
}
