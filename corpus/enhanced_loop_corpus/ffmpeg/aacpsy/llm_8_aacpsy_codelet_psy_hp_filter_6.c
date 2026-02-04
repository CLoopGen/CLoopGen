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
for (i = 0; i < 512; i++) {
    float sum1, sum2;
    sum1 = firbuf[i + (15 - 1) / 2];
    sum2 = 0.;
    for (j = 0; j < ((15 - 1) / 2) - 1; j += 2) {
        sum1 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 15 - j]);
        sum2 += psy_fir_coeffs[j + 1] * (firbuf[i + j + 1] + firbuf[i + 15 - j - 1]);
    }
    hpfsmpl[i] = (sum1 + sum2) * 16384.F;
}
}
