#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rotations = 0;
    for (; normalized_degrees > 45.; )
    {
        normalized_degrees -= 90.;
        rotations++;
        if (rotations >= 1000000) break; // Safety limit to prevent infinite loops
    }
}
