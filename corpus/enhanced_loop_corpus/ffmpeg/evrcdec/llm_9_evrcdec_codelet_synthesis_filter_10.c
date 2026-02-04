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
        float temp_sum = 0.0f;
        for (j = 0; j < 10; j++) {
            temp_sum += filter_coeffs[j] * memory[9 - j];
        }
        samples[i] -= temp_sum;
        for (j = 9; j > 0; j--) {
            memory[j] = memory[j - 1];
        }
        memory[0] = samples[i];
    }
}
