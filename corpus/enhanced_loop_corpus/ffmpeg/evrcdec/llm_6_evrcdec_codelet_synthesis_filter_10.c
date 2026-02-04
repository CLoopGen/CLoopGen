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
    float temp;
    for (i = 0; i < buffer_length; i++) {
        temp = in[i];
        for (j = 10 - 1; j > 0; j--) {
            temp -= filter_coeffs[j] * memory[j];
            memory[j] = memory[j - 1];
        }
        temp -= filter_coeffs[0] * memory[0];
        memory[0] = temp;
        samples[i] = temp;
    }
}
