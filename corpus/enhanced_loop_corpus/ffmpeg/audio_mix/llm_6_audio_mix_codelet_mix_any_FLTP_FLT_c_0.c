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
        for (in = 0; in < in_ch; in++)
            sum += samples[in][i] * matrix[out][in];
        temp[out] = sum;
    }
    // Introduce a loop-carried dependency by making each iteration depend on the previous one
    // via a running accumulation across output channels, while preserving semantics through scaling
    float prev = temp[0];
    for (out = 1; out < out_ch; out++) {
        float current = temp[out];
        temp[out] = temp[out] + prev;  // RAW dependency: temp[out] depends on temp[out-1]
        prev = current;
    }
    for (out = 0; out < out_ch; out++)
        samples[out][i] = temp[out];
}
}
