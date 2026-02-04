#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_low[7];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset precomputation
    float *out_base = output + (2 * 9 - 13); // Precompute starting point for i=9
    const int stride = 2;
    for (i = 9; i < findex + 11; i++) {
        const float t_val = temp[i];
        const float a = t_val * synthesis_low[0];
        const float b = t_val * synthesis_low[1];
        const float c = t_val * synthesis_low[2];
        const float d = t_val * synthesis_low[3];
        
        // Access output consecutively by maintaining running pointer
        float *out_ptr = out_base;
        out_ptr[0] += a;
        out_ptr[1] += b;
        out_ptr[2] += c;
        out_ptr[3] += d;
        out_ptr[4] += c;
        out_ptr[5] += b;
        out_ptr[6] += a;

        // Move base pointer by stride for next iteration
        out_base += stride;
    }
}
