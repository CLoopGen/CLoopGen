#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b12_1;
extern  float b12_6;
extern  float b12_7;
extern  float b12_8;
extern  float b12_9;
extern  float b12_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float sum = 0.0f;
    for (int j = 0; j < 6; j++) {
        int offset[] = {0, 5, 6, 7, 8, 9};
        float coeffs[] = {b12_1, b12_6, b12_7, b12_8, b12_9, b12_10};
        sum += coeffs[j] * finavalu_temp[offset[j]][idx];
    }
    initvalu_temp[idx] = initvalu[idx] + h * sum;
    if (i >= 91) break;
}
}
