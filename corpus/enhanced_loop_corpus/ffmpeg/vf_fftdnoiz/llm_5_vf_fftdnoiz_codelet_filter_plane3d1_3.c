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
        int index;
        for (i = 0; i < block; i++) {
            // Flattened inner two loops into a single loop with manual indexing
            for (index = 0; index < block; index++) {
                float factor, power, re, im, pre, pim;
                float sumr, sumi, difr, difi;
                int offset = index * 2;
                re = cbuff[offset];
                pre = pbuff[offset];
                im = cbuff[offset + 1];
                pim = pbuff[offset + 1];
                sumr = re + pre;
                sumi = im + pim;
                difr = re - pre;
                difi = im - pim;

                // First threshold check: apply clamping without branching using conditional-like arithmetic
                power = sumr * sumr + sumi * sumi + 1.0E-15F;
                factor = (power - sigma) / power;
                // Simulate max(limit, factor) without branching using arithmetic
                factor = limit + ((factor - limit) > 0.0F ? (factor - limit) : 0.0F);
                sumr *= factor;
                sumi *= factor;

                power = difr * difr + difi * difi + 1.0E-15F;
                factor = (power - sigma) / power;
                factor = limit + ((factor - limit) > 0.0F ? (factor - limit) : 0.0F);
                difr *= factor;
                difi *= factor;

                cbuff[offset] = (sumr + difr) * 0.5F;
                cbuff[offset + 1] = (sumi + difi) * 0.5F;
            }
            cbuff += buffer_linesize;
            pbuff += buffer_linesize;
        }
    }
}
}
