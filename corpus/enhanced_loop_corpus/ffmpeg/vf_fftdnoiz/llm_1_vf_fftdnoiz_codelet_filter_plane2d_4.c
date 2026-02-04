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
        i = 0;
        do {
            j = 0;
            do {
                float factor, power, re, im;
                re = buff[j * 2];
                im = buff[j * 2 + 1];
                power = re * re + im * im + 1.0E-15F;
                factor = ((limit) > ((power - sigma) / power) ? (limit) : ((power - sigma) / power));
                buff[j * 2] *= factor;
                buff[j * 2 + 1] *= factor;
                j++;
            } while (j < block);
            buff += buffer_linesize;
            i++;
        } while (i < block);
    }
}
}
