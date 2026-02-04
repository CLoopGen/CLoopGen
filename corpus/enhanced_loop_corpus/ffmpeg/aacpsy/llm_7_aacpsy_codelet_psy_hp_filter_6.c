#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *firbuf;
extern float *hpfsmpl;
extern  float *psy_fir_coeffs;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1, sum2;
    for (i = 0; i < 1024; i++) {
        sum1 = 0.0f;
        sum2 = 0.0f;
        int offset = i + 10;
        sum1 = firbuf[offset];
        for (j = 0; j < 9; j += 2) {
            int idx1 = i + j;
            int idx2 = i + 21 - j;
            int idx3 = i + j + 1;
            int idx4 = i + 21 - j - 1;
            sum1 += psy_fir_coeffs[j] * (firbuf[idx1] + firbuf[idx2]);
            sum2 += psy_fir_coeffs[j + 1] * (firbuf[idx3] + firbuf[idx4]);
        }
        hpfsmpl[i] = (sum1 + sum2) * 32768.F;
    }
}
