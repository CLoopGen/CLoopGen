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
    for (i = 0; i < 40; i++) {
        out[i] = 0.0f;
        for (j = 0; j <= 30; j += 2) {
            out[i] += data[i + j] * fir_coef[j];
            if (j + 1 <= 30) {
                out[i] += data[i + j + 1] * fir_coef[j + 1];
            }
        }
    }
}
