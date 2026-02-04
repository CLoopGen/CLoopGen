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
    float temp_buffer[10];
    for (i = 0; i < buffer_length; i++) {
        samples[i] = in[i];
        for (j = 0; j < 10 - 1; j++) {
            temp_buffer[j] = memory[j];
        }
        for (j = 10 - 1; j > 0; j--) {
            samples[i] -= filter_coeffs[j] * temp_buffer[j - 1];
            memory[j] = temp_buffer[j - 1];
        }
        samples[i] -= filter_coeffs[0] * memory[0];
        memory[0] = samples[i];
    }
}
