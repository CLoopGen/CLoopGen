#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pbuffer;
extern  int block;
extern  int nox;
extern  int noy;
extern  int buffer_linesize;
extern  float sigma;
extern  float limit;
extern float *cbuffer;
extern int y;
extern int x;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < noy; y += 2) {
    for (x = 0; x < nox; x += 2) {
        for (int offset_y = 0; offset_y < 2 && (y + offset_y) < noy; ++offset_y) {
            for (int offset_x = 0; offset_x < 2 && (x + offset_x) < nox; ++offset_x) {
                int curr_y = y + offset_y;
                int curr_x = x + offset_x;
                float *cbuff = cbuffer + buffer_linesize * curr_y * block + curr_x * block * 2;
                float *pbuff = pbuffer + buffer_linesize * curr_y * block + curr_x * block * 2;
                for (i = 0; i < block; i++) {
                    for (j = 0; j < block; j++) {
                        float re = cbuff[j * 2], im = cbuff[j * 2 + 1];
                        float pre = pbuff[j * 2], pim = pbuff[j * 2 + 1];
                        float sumr = re + pre, sumi = im + pim;
                        float difr = re - pre, difi = im - pim;
                        float power = sumr * sumr + sumi * sumi + 1.0E-15F;
                        float factor = (limit > (power - sigma) / power) ? limit : (power - sigma) / power;
                        sumr *= factor; sumi *= factor;
                        power = difr * difr + difi * difi + 1.0E-15F;
                        factor = (limit > (power - sigma) / power) ? limit : (power - sigma) / power;
                        difr *= factor; difi *= factor;
                        cbuff[j * 2] = (sumr + difr) * 0.5F;
                        cbuff[j * 2 + 1] = (sumi + difi) * 0.5F;
                    }
                    cbuff += buffer_linesize;
                    pbuff += buffer_linesize;
                }
            }
        }
    }
}
}
