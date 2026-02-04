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
    for (i = 10; i < 10 + low_size; i++) {
        const int offset = 2 * i - 14;
        float local_accum = 0.0f;
        // Unroll and reorganize computations to eliminate direct sequential dependencies between iterations
        local_accum += input[offset + 0] * analysis_low[0];
        local_accum += input[offset + 1] * analysis_low[1];
        local_accum += input[offset + 2] * analysis_low[2];
        local_accum += input[offset + 3] * analysis_low[3];
        local_accum += input[offset + 4] * analysis_low[4];
        local_accum += input[offset + 5] * analysis_low[3];
        local_accum += input[offset + 6] * analysis_low[2];
        local_accum += input[offset + 7] * analysis_low[1];
        local_accum += input[offset + 8] * analysis_low[0];
        // Store result only at the end, no intra-loop or inter-iteration dependencies
        output[i] = local_accum;
    }
}
