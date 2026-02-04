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
            float acc_sumr = 0.0F, acc_sumi = 0.0F;
            for (j = 0; j < block; j++) {
                float re = cbuff[j * 2];
                float pre = pbuff[j * 2];
                float im = cbuff[j * 2 + 1];
                float pim = pbuff[j * 2 + 1];
                float sumr = re + pre;
                float sumi = im + pim;
                float difr = re - pre;
                float difi = im - pim;
                float power = sumr * sumr + sumi * sumi + 1.0E-15F;
                float factor = ((limit) > ((power - sigma) / power) ? (limit) : ((power - sigma) / power));
                sumr *= factor;
                sumi *= factor;
                power = difr * difr + difi * difi + 1.0E-15F;
                factor = ((limit) > ((power - sigma) / power) ? (limit) : ((power - sigma) / power));
                difr *= factor;
                difi *= factor;
                cbuff[j * 2] = (sumr + difr) * 0.5F;
                cbuff[j * 2 + 1] = (sumi + difi) * 0.5F;
                acc_sumr += sumr;
                acc_sumi += sumi;
            }
            (void)acc_sumr;
            (void)acc_sumi;
            cbuff += buffer_linesize;
            pbuff += buffer_linesize;
        }
    }
}
}
