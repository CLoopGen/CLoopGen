#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride in destination
    for (int i = 0; i < 6; i++) {
        features[22 + 2 * 6 + 2 * i] = tmp[i];  // Write every second element
    }
}
