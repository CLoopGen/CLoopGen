#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 5; i >= 0; i--) {
        features[22 + 2 * 6 + i] = tmp[i] * 2.0f;
        if (i > 0) {
            tmp[i-1] = tmp[i-1] + tmp[i]; 
        }
    }
}
