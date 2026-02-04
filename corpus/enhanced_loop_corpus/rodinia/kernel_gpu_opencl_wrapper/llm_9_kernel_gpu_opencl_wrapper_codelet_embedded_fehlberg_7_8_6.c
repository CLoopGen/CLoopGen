#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b71;
extern  float b74;
extern  float b75;
extern  float b76;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i] * b71;
    float term2 = finavalu_temp[3][i] * b74;
    float term3 = finavalu_temp[4][i] * b75;
    float term4 = finavalu_temp[5][i] * b76;
    float sum1 = term1 + term2;
    float sum2 = term3 + term4;
    float total = sum1 + sum2;
    initvalu_temp[i] = initvalu[i] + h * total;
    initvalu_temp[90 - i] = initvalu[90 - i] + h * total; // Symmetric update increases computational intensity
}
}
