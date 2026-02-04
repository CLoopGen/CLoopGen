#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_normalized = normalized_degrees;
    int local_rotations = 0;
    for (double step = local_normalized; step > 45.; step -= 90.) {
        local_rotations++;
        local_normalized = step - 90.; // Introduce WAW dependency with artificial update
    }
    rotations = local_rotations;
}
