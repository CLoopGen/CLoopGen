#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int block;
extern  int nox;
extern  int noy;
extern  int buffer_linesize;
extern  float sigma;
extern  float limit;
extern float *buffer;
extern int y;
extern int x;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < noy; y++) {
    for (x = 0; x < nox; x++) {
        float *buff = buffer + buffer_linesize * y * block + x * block * 2;
        for (i = 0; i < block; i++) {
            float sum_re = 0.0f, sum_im = 0.0f;
            for (j = 0; j < block; j++) {
                float re, im, power, factor;
                re = buff[j * 2];
                im = buff[j * 2 + 1];
                sum_re += re;
                sum_im += im;
                power = re * re + im * im + 1.0E-15F;
                factor = (power - sigma) / power;
                if (factor < limit) factor = limit;
                buff[j * 2] = re * factor;
                buff[j * 2 + 1] = im * factor;
            }
            float avg_re = sum_re / block;
            float avg_im = sum_im / block;
            buff[0] += avg_re * 0.01f;
            buff[1] += avg_im * 0.01f;
            buff += buffer_linesize;
        }
    }
}
}
