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
for (y = 0; y < noy; y++) {
    for (x = 0; x < nox; x++) {
        float *cbuff = cbuffer + buffer_linesize * y * block + x * block * 2;
        float *pbuff = pbuffer + buffer_linesize * y * block + x * block * 2;
        for (i = 0; i < block; i++) {
            for (j = 0; j < block; j++) {
                float factor, power, re, im, pre, pim;
                float sumr, sumi, difr, difi;
                int idx = j * 2;
                re = cbuff[idx];
                pre = pbuff[idx];
                im = cbuff[idx + 1];
                pim = pbuff[idx + 1];
                sumr = re + pre;
                sumi = im + pim;
                difr = re - pre;
                difi = im - pim;
                power = sumr * sumr + sumi * sumi + 1.0E-15F;
                factor = ((limit) > ((power - sigma) / power) ? (limit) : ((power - sigma) / power));
                sumr *= factor;
                sumi *= factor;
                power = difr * difr + difi * difi + 1.0E-15F;
                factor = ((limit) > ((power - sigma) / power) ? (limit) : ((power - sigma) / power));
                difr *= factor;
                difi *= factor;
                cbuff[idx] = (sumr + difr) * 0.5F;
                cbuff[idx + 1] = (sumi + difi) * 0.5F;
            }
            cbuff += buffer_linesize;
            pbuff += buffer_linesize;
        }
    }
}
}
