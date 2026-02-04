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
            for (j = 0; j < block; j += 2) {
                float factor1, power1, re1, im1, pre1, pim1;
                float sumr1, sumi1, difr1, difi1;
                float factor2, power2, re2, im2, pre2, pim2;
                float sumr2, sumi2, difr2, difi2;

                re1 = cbuff[j * 2];
                pre1 = pbuff[j * 2];
                im1 = cbuff[j * 2 + 1];
                pim1 = pbuff[j * 2 + 1];
                sumr1 = re1 + pre1;
                sumi1 = im1 + pim1;
                difr1 = re1 - pre1;
                difi1 = im1 - pim1;
                power1 = sumr1 * sumr1 + sumi1 * sumi1 + 1.0E-15F;
                factor1 = ((limit) > ((power1 - sigma) / power1) ? (limit) : ((power1 - sigma) / power1));
                sumr1 *= factor1;
                sumi1 *= factor1;
                power1 = difr1 * difr1 + difi1 * difi1 + 1.0E-15F;
                factor1 = ((limit) > ((power1 - sigma) / power1) ? (limit) : ((power1 - sigma) / power1));
                difr1 *= factor1;
                difi1 *= factor1;
                cbuff[j * 2] = (sumr1 + difr1) * 0.5F;
                cbuff[j * 2 + 1] = (sumi1 + difi1) * 0.5F;

                if (j + 1 < block) {
                    re2 = cbuff[(j+1) * 2];
                    pre2 = pbuff[(j+1) * 2];
                    im2 = cbuff[(j+1) * 2 + 1];
                    pim2 = pbuff[(j+1) * 2 + 1];
                    sumr2 = re2 + pre2;
                    sumi2 = im2 + pim2;
                    difr2 = re2 - pre2;
                    difi2 = im2 - pim2;
                    power2 = sumr2 * sumr2 + sumi2 * sumi2 + 1.0E-15F;
                    factor2 = ((limit) > ((power2 - sigma) / power2) ? (limit) : ((power2 - sigma) / power2));
                    sumr2 *= factor2;
                    sumi2 *= factor2;
                    power2 = difr2 * difr2 + difi2 * difi2 + 1.0E-15F;
                    factor2 = ((limit) > ((power2 - sigma) / power2) ? (limit) : ((power2 - sigma) / power2));
                    difr2 *= factor2;
                    difi2 *= factor2;
                    cbuff[(j+1) * 2] = (sumr2 + difr2) * 0.5F;
                    cbuff[(j+1) * 2 + 1] = (sumi2 + difi2) * 0.5F;
                }
            }
            cbuff += buffer_linesize;
            pbuff += buffer_linesize;
        }
    }
}
}
