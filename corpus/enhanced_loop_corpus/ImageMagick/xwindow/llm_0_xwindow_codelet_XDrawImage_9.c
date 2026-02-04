#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rotations = 0;
    double temp_normalized_degrees = normalized_degrees;
    for (; temp_normalized_degrees > 45.; temp_normalized_degrees -= 90.) {
        for (int inner = 0; inner < 1; inner++) {
            temp_rotations++;
        }
    }
    rotations = temp_rotations;
}
