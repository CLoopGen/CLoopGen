#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3; i++) {
        float val0 = tmp[i] + 0.1f;
        float val1 = tmp[i + 3] - 0.1f;
        features[34 + i * 2]     = val0;
        features[34 + i * 2 + 1] = val1;
    }
}
