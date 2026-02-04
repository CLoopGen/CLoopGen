#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rotations = 0; normalized_degrees > 45.; rotations++) {
    for (int inner = 0; inner < 1; inner++) {
        normalized_degrees -= 90.;
    }
}
}
