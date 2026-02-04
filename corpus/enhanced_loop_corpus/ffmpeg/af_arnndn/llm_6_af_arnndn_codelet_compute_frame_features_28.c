#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_accum = 0.0f;
    for (int i = 0; i < 6; i++) {
        temp_accum += tmp[i];
        features[22 + 2 * 6 + i] = temp_accum;
    }
}
