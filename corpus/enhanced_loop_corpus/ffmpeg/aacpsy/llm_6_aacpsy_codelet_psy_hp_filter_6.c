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
        sum1 = firbuf[i + 10];
        sum2 = 0.0f;
        for (j = 0; j < 9; j += 2) {
            float temp1 = firbuf[i + j] + firbuf[i + 21 - j];
            float temp2 = firbuf[i + j + 1] + firbuf[i + 21 - j - 1];
            sum1 += psy_fir_coeffs[j] * temp1;
            sum2 += psy_fir_coeffs[j + 1] * temp2;
        }
        hpfsmpl[i] = (sum1 + sum2) * 32768.F;
    }
}
