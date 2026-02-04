#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (rotations = 0; normalized_degrees > 45.; rotations++)
    normalized_degrees -= 90.;

}
