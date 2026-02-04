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
for (i = 0; i < len; i += 2) {
    int i1 = i + 1;
    for (out = 0; out < out_ch; out++) {
        float sum0 = 0;
        float sum1 = 0;
        for (in = 0; in < in_ch; in++) {
            float s = samples[in][i];
            sum0 += s * matrix[out][in];
            if (i1 < len) {
                sum1 += samples[in][i1] * matrix[out][in];
            }
        }
        temp[out] = sum0;
        if (i1 < len) {
            samples[out][i1] = sum1;
        }
    }
    for (out = 0; out < out_ch; out++) {
        samples[out][i] = temp[out];
    }
}
}
