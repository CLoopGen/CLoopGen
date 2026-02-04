#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rotations = 0;
    double temp_degrees = normalized_degrees;
    for (; temp_degrees > 45.0; temp_rotations++) {
        temp_degrees -= 45.0;
        temp_degrees -= 45.0;  // Two smaller subtractions instead of one - increased arithmetic operations
    }
    rotations = temp_rotations;
}
