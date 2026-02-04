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
        int j1;
        for (j1 = 0; j1 <= 15; j1++)
            out[i] += data[i + j1] * fir_coef[j1];
        int j2;
        for (j2 = 16; j2 <= 30; j2++)
            out[i] += data[i + j2] * fir_coef[j2];
    }
}
