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
    for (out = 0; out < out_ch; out += 2) {
        float sum0 = 0;
        float sum1 = 0;
        for (in = 0; in < in_ch; in++) {
            sum0 += samples[in][i] * matrix[out][in];
            if (out + 1 < out_ch) {
                sum1 += samples[in][i] * matrix[out + 1][in];
            }
        }
        temp[out] = sum0;
        if (out + 1 < out_ch) {
            temp[out + 1] = sum1;
        }
    }
    for (out = 0; out < out_ch; out++)
        samples[out][i] = temp[out];
}
}
