#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern  float *filter_coeffs;
extern float *memory;
extern int buffer_length;
extern float *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < buffer_length; i += 2) {
        for (int unroll_idx = 0; unroll_idx < 2 && (i + unroll_idx) < buffer_length; unroll_idx++) {
            int idx = i + unroll_idx;
            samples[idx] = in[idx];
            for (j = 10 - 1; j >= 0; j--) {
                if (j > 0) {
                    samples[idx] -= filter_coeffs[j] * memory[j];
                    memory[j] = memory[j - 1];
                } else {
                    samples[idx] -= filter_coeffs[0] * memory[0];
                    memory[0] = samples[idx];
                }
            }
        }
    }
}
