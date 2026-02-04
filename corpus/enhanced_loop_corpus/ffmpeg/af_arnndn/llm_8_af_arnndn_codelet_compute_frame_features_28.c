#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 12; i += 2) {
        features[34 + i] = tmp[i / 2];
        features[35 + i] = tmp[i / 2] * 1.5f;
    }
}
