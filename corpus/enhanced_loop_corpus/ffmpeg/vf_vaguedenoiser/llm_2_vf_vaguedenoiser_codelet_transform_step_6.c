#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_high[7];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with array base offset pre-computation
    float *input_base = &input[2 * 10 - 12]; // Precompute starting point for input
    for (i = 10; i < 10 + low_size; i++) {
        int idx = 2 * (i - 10); // Convert to sequential index from base
        const float a = input_base[idx + 0] * analysis_high[0];
        const float b = input_base[idx + 2] * analysis_high[1];
        const float c = input_base[idx + 4] * analysis_high[2];
        const float d = input_base[idx + 6] * analysis_high[3];
        const float e = input_base[idx + 8] * analysis_high[2];
        const float f = input_base[idx + 10] * analysis_high[1];
        const float g = input_base[idx + 12] * analysis_high[0];
        output[i + low_size] = a + b + c + d + e + f + g;
    }
}
