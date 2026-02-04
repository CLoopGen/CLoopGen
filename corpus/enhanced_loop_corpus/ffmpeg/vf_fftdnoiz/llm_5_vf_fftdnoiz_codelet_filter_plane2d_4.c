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
            int skip_row = 0;
            // Introduce control dependency: skip processing this row if average magnitude is too low
            float sum_power = 0.0F;
            for (j = 0; j < block; j++) {
                float re = buff[j * 2];
                float im = buff[j * 2 + 1];
                sum_power += re * re + im * im;
            }
            if (sum_power / block < sigma * 0.5F) {
                skip_row = 1;
            }
            if (!skip_row) {
                for (j = 0; j < block; j++) {
                    float factor, power, re, im;
                    re = buff[j * 2];
                    im = buff[j * 2 + 1];
                    power = re * re + im * im + 1.0E-15F;
                    factor = (power - sigma) / power;
                    if (factor < limit) {
                        factor = limit;
                    }
                    buff[j * 2] *= factor;
                    buff[j * 2 + 1] *= factor;
                }
            }
            buff += buffer_linesize;
        }
    }
}
}
