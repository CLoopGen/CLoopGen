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
float temp_sum[1024][2];
for (i = 0; i < 1024; i++) {
    temp_sum[i][0] = firbuf[i + 10];
    temp_sum[i][1] = 0.0f;
}
for (j = 0; j < 9; j += 2) {
    for (i = 0; i < 1024; i++) {
        temp_sum[i][0] += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
        if (j + 1 < 9) {
            temp_sum[i][1] += psy_fir_coeffs[j + 1] * (firbuf[i + j + 1] + firbuf[i + 21 - j - 1]);
        }
    }
}
for (i = 0; i < 1024; i++) {
    hpfsmpl[i] = (temp_sum[i][0] + temp_sum[i][1]) * 32768.0f;
}
}
