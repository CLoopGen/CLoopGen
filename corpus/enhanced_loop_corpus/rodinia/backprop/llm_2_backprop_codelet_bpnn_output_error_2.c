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
    // Variant 1: Consecutive memory access with array base offset applied once
    float *delta_base = delta + 1;
    float *target_base = target + 1;
    float *output_base = output + 1;
    float errsum_local = 0.0f;
    
    for (int i = 0; i < nj; i++) {
        float o_val = output_base[i];
        float t_val = target_base[i];
        float delta_val = o_val * (1.0f - o_val) * (t_val - o_val);
        delta_base[i] = delta_val;
        errsum_local += (delta_val > 0.0f) ? delta_val : -delta_val;
    }
    errsum += errsum_local;
}
