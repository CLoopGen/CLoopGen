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
            for (j = 0; j < block; j++) {
                float factor, power, re, im;
                re = buff[j * 2];
                im = buff[j * 2 + 1];
                power = re * re + im * im + 1.0E-15F;
                // Removed conditional ternary by precomputing and clamping with an early exit condition
                float temp_factor = (power - sigma) / power;
                if (temp_factor <= limit) {
                    factor = limit;
                } else {
                    factor = temp_factor;
                }
                buff[j * 2] *= factor;
                buff[j * 2 + 1] *= factor;
            }
            buff += buffer_linesize;
        }
    }
}
}
