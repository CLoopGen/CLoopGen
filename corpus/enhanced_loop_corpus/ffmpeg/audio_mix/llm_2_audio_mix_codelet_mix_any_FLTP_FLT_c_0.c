#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int len;
extern int out_ch;
extern int in_ch;
extern int i;
extern int in;
extern int out;
extern float temp[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    for (out = 0; out < out_ch; out++) {
        float sum = 0;
        // Change memory access to stride by 1 through input channels, but access samples with positive offset pattern
        for (in = 0; in < in_ch; in += 1)
            sum += samples[in][i] * matrix[out][in];
        temp[out] = sum;
    }
    // Write back results using reversed order of output channels to modify store pattern
    for (out = out_ch - 1; out >= 0; out--)
        samples[out][i] = temp[out];
}
}
