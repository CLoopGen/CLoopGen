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
            float factor_accum[block];
            float re_vals[block], im_vals[block], power_vals[block];
            for (j = 0; j < block; j++) {
                re_vals[j] = buff[j * 2];
                im_vals[j] = buff[j * 2 + 1];
                power_vals[j] = re_vals[j] * re_vals[j] + im_vals[j] * im_vals[j] + 1.0E-15F;
                factor_accum[j] = ((limit) > ((power_vals[j] - sigma) / power_vals[j]) ? (limit) : ((power_vals[j] - sigma) / power_vals[j]));
            }
            for (j = 0; j < block; j++) {
                buff[j * 2] *= factor_accum[j];
                buff[j * 2 + 1] *= factor_accum[j];
            }
            buff += buffer_linesize;
        }
    }
}
}
