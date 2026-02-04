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
    for (in = 0; in < in_ch; in++) {
        for (out = 0; out < out_ch; out++) {
            if (in == 0) {
                temp[out] = 0;
            }
            temp[out] += samples[in][i] * matrix[out][in];
        }
    }
    for (out = 0; out < out_ch; out++) {
        samples[out][i] = temp[out];
    }
}
}
