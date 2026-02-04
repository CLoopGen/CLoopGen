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
for (y = 0; y < noy; y += 2) {
    for (x = 0; x < nox; x += 2) {
        float *buff = buffer + buffer_linesize * y * block + x * block * 2;
        for (i = 0; i < block; i++) {
            for (j = 0; j < block; j += 2) {
                float factor1, power1, re1, im1;
                float factor2, power2, re2, im2;
                re1 = buff[j * 2];
                im1 = buff[j * 2 + 1];
                power1 = re1 * re1 + im1 * im1 + 1.0E-15F;
                factor1 = ((limit) > ((power1 - sigma) / power1) ? (limit) : ((power1 - sigma) / power1));
                buff[j * 2] *= factor1;
                buff[j * 2 + 1] *= factor1;

                if (j + 1 < block) {
                    re2 = buff[(j + 1) * 2];
                    im2 = buff[(j + 1) * 2 + 1];
                    power2 = re2 * re2 + im2 * im2 + 1.0E-15F;
                    factor2 = ((limit) > ((power2 - sigma) / power2) ? (limit) : ((power2 - sigma) / power2));
                    buff[(j + 1) * 2] *= factor2;
                    buff[(j + 1) * 2 + 1] *= factor2;
                }
            }
            buff += buffer_linesize;
        }
    }
}
}
