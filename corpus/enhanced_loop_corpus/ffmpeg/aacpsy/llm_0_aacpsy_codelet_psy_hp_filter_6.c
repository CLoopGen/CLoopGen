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
    sum2 = 0.0f;
    int k = 0;
    for (j = 0; j < 9; j++) {
        if (j % 2 == 0) {
            sum1 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
        } else {
            sum2 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
        }
    }
    hpfsmpl[i] = (sum1 + sum2) * 32768.0f;
}
}
