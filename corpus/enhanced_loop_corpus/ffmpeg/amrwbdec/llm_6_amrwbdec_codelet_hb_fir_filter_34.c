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
    float temp_out[80];
    for (i = 0; i < 80; i++) {
        temp_out[i] = 0.0;
        for (j = 0; j <= 30; j++)
            temp_out[i] += data[i + j] * fir_coef[j];
    }
    for (i = 0; i < 80; i++) {
        out[i] = temp_out[i];
    }
}
