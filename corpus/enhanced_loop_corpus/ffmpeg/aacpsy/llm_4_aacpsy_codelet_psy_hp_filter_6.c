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
for (i = 0; i < 1024; i++) {
    float sum1, sum2;
    sum1 = firbuf[i + 10];
    sum2 = 0.;
    for (j = 0; j < 9; j += 2) {
        if (psy_fir_coeffs[j] > 0.0f) {
            sum1 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
        }
        if (psy_fir_coeffs[j + 1] > 0.0f) {
            sum2 += psy_fir_coeffs[j + 1] * (firbuf[i + j + 1] + firbuf[i + 21 - j - 1]);
        }
    }
    hpfsmpl[i] = (sum1 + sum2) * 32768.F;
}
}
