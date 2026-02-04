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
    for (i = 0; i < 80; i++) {
        out[i] = 0.;
        if (i % 2 == 0) {
            for (j = 0; j <= 30; j++)
                out[i] += data[i + j] * fir_coef[j];
        } else {
            for (j = 0; j <= 15; j++)
                out[i] += data[i + j] * fir_coef[j];
            for (; j <= 30; j++)
                out[i] += data[i + j] * fir_coef[j];
        }
    }
}
