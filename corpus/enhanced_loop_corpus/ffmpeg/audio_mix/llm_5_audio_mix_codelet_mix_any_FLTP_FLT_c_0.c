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
    if (i % 2 == 0) {
        for (out = 0; out < out_ch; out++) {
            float sum = 0;
            for (in = 0; in < in_ch; in++) {
                sum += samples[in][i] * matrix[out][in];
            }
            temp[out] = sum;
        }
        for (out = 0; out < out_ch; out++) {
            samples[out][i] = temp[out];
        }
    } else {
        for (out = 0; out < out_ch; out++) {
            temp[out] = 0.0f;
            for (in = 0; in < in_ch; in++) {
                temp[out] += samples[in][i] * matrix[out][in] * 0.5f;
            }
            samples[out][i] = temp[out];
        }
    }
}
}
