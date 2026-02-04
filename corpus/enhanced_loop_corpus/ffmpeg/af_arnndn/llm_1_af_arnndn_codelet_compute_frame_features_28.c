#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3; i++) {
        features[22 + 12 + i] = tmp[i];
        features[22 + 12 + i + 3] = tmp[i + 3];
    }
}
