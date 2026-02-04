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
        int trip_count = (int)((normalized_degrees - 45.0) / 90.0) + 1;
        for (int i = 0; i < trip_count; i++) {
            rotations++;
            // Simulate higher computational load with dummy operations
            volatile double scratch = normalized_degrees;
            scratch *= 1.0001;
            scratch /= 1.0001;
            normalized_degrees = scratch - 90.0;
        }
    }
}
