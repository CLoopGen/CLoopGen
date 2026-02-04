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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 0; i < 896; i++) {
        float index_factor = (float)(1792 - 2*i - 1);
        float weight_a = a * index_factor * index_factor;  // Squared term increases computation
        float weight_b = b * (2.0f * i) * (i / 256.0f + 1.0f);  // Additional scaling and division
        output[i] *= (weight_a + weight_b) * 0.5f;
    }
}
