#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *delta;
extern float *target;
extern float *output;
extern int nj;
extern int j;
extern float o;
extern float t;
extern float errsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing every second element
    float errsum_local = 0.0f;
    
    // Process even indices: j = 1, 3, 5, ..., up to nj
    for (int idx = 1; idx <= nj; idx += 2) {
        float o_val = output[idx];
        float t_val = target[idx];
        float delta_val = o_val * (1.0f - o_val) * (t_val - o_val);
        delta[idx] = delta_val;
        errsum_local += (delta_val > 0.0f) ? delta_val : -delta_val;
    }

    // Process odd indices: j = 2, 4, 6, ..., up to nj
    for (int idx = 2; idx <= nj; idx += 2) {
        float o_val = output[idx];
        float t_val = target[idx];
        float delta_val = o_val * (1.0f - o_val) * (t_val - o_val);
        delta[idx] = delta_val;
        errsum_local += (delta_val > 0.0f) ? delta_val : -delta_val;
    }

    errsum += errsum_local;
}
