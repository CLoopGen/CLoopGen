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
    // Variant 1: Increased computational intensity by unrolling the loop with trip count reduction
    // and adding extra arithmetic operations (squaring terms) to increase compute load.
    int i;
    for (i = 0; i < n; i += 2) {
        // First iteration of unrolled loop
        if (i < n) {
            tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
            out[i] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
            // Add extra computation: apply a non-linear correction via squaring
            out[i] += (mem[0] * mem[0]) * 0.01f;
            mem[1] = mem[0];
            mem[0] = tmp;
        }
        // Second iteration of unrolled loop
        if (i + 1 < n) {
            tmp = gain * in[i+1] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
            out[i+1] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
            // Extra computation: another scaled square term
            out[i+1] += (mem[1] * mem[1]) * 0.01f;
            mem[1] = mem[0];
            mem[0] = tmp;
        }
    }
}
