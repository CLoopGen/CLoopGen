#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_low[9];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal pattern
    // Access input in a strided manner by reversing the order of coefficient application
    for (i = 10; i < 10 + low_size; i++) {
        float sum = 0.0f;
        const int start_idx = 2 * i - 14;
        // Apply coefficients in reverse order using stride of 2 on effective taps
        for (int j = 0; j < 9; j++) {
            const int tap_idx = (j <= 4) ? j : 8 - j; // Symmetric coefficient indexing
            const int input_offset = start_idx + j;
            sum += input[input_offset] * analysis_low[tap_idx];
        }
        output[i] = sum;
    }
}
