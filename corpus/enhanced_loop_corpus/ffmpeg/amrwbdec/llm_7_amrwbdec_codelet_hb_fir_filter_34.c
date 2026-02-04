#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float fir_coef[31];
extern int i;
extern int j;
extern float data[110];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    out[0] = 0.0;
    for (j = 0; j <= 30; j++)
        out[0] += data[j] * fir_coef[j];
    for (i = 1; i < 80; i++) {
        out[i] = out[i-1] - data[i-1] * fir_coef[0];
        for (j = 1; j <= 30; j++) {
            if (i + j < 110)
                out[i] += data[i + j] * fir_coef[j];
        }
    }
}
