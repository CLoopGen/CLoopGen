#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern float a;
extern float b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified operations
    for (i = 0; i < 3584; i += 2) {
        int idx = i >> 1;  // equivalent to i / 2
        float coeff = a * (1792 - idx) + b * idx;
        output[idx] *= coeff;
        if (i + 1 < 3584 && idx + 1 < 1792) {
            output[idx + 1] *= coeff;  // Reuse computed coeff for adjacent element
        }
    }
}
