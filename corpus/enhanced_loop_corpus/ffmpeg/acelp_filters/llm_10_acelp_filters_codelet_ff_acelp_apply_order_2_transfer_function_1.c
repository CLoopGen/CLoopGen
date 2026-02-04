#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float zero_coeffs[2];
extern  float pole_coeffs[2];
extern float gain;
extern float mem[2];
extern int n;
extern int i;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer memory updates and simplified arithmetic.
    // Trip count remains same but operations per iteration are reduced by removing one coefficient use.
    // Approximate filtering with only first-order memory dependence.
    int i;
    for (i = 0; i < n; i++) {
        // Remove dependence on mem[1] to reduce state complexity
        tmp = gain * in[i] - pole_coeffs[0] * mem[0];  // Ignore pole_coeffs[1] * mem[1]
        out[i] = tmp + zero_coeffs[0] * mem[0];      // Ignore zero_coeffs[1] * mem[1]
        // Update memory with decayed average instead of direct assignment to reduce sensitivity
        mem[0] = 0.95f * tmp + 0.05f * mem[0];
        // mem[1] is no longer used, effectively reducing state to first order
    }
}
