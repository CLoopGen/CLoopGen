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
for (i = 0; i < buffer_length; i++) {
    samples[i] = in[i];
    if (i % 2 == 0) {
        for (j = 10 - 1; j > 0; j--) {
            samples[i] -= filter_coeffs[j] * memory[j];
            memory[j] = memory[j - 1];
        }
        samples[i] -= filter_coeffs[0] * memory[0];
        memory[0] = samples[i];
    } else {
        for (j = 10 - 1; j >= 0; j--) {
            float coeff = filter_coeffs[j];
            float mem_val = (j > 0) ? memory[j] : memory[0];
            if (j > 0) {
                samples[i] -= coeff * mem_val;
                memory[j] = memory[j - 1];
            } else {
                samples[i] -= coeff * mem_val;
            }
        }
        memory[0] = samples[i];
    }
}
}
