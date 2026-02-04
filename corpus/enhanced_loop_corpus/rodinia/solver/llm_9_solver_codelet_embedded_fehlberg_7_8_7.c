#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b81;
extern  float b85;
extern  float b86;
extern  float b87;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i++) {
    float term1 = b81 * finavalu_temp[0][i];
    float term2 = b85 * finavalu_temp[4][i];
    float term3 = b86 * finavalu_temp[5][i];
    float term4 = b87 * finavalu_temp[6][i];
    float sum1 = term1 + term2;
    float sum2 = term3 + term4;
    float total = sum1 + sum2;
    initvalu_temp[i] = initvalu[i] + h * total;
}
}
