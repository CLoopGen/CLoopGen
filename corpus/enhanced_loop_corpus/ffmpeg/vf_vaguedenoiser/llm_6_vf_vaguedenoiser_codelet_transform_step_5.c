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
    float temp_sum = 0.0f;
    for (i = 10; i < 10 + low_size; i++) {
        const int idx = 2 * i - 14;
        temp_sum += input[idx] * analysis_low[0];
        output[i] = temp_sum; // Introduce WAW and RAW dependencies: each iteration depends on previous output and accumulates state
        temp_sum = output[i] * 0.95f; // Create loop-carried dependency via temp_sum; modifies value used in next iteration
    }
}
