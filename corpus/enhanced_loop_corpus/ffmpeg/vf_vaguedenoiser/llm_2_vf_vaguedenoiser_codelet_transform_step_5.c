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
    // Variant 1: Consecutive memory access with offset adjustment
    // Reorganize input accesses to be consecutive by precomputing base index
    for (i = 10; i < 10 + low_size; i++) {
        const int base_idx = 2 * i - 14;
        const float a = input[base_idx + 0] * analysis_low[0];
        const float b = input[base_idx + 1] * analysis_low[1];
        const float c = input[base_idx + 2] * analysis_low[2];
        const float d = input[base_idx + 3] * analysis_low[3];
        const float e = input[base_idx + 4] * analysis_low[4];
        const float f = input[base_idx + 5] * analysis_low[3];
        const float g = input[base_idx + 6] * analysis_low[2];
        const float h = input[base_idx + 7] * analysis_low[1];
        const float k = input[base_idx + 8] * analysis_low[0];
        output[i] = a + b + c + d + e + f + g + h + k;
    }
}
