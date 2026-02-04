#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b11_1;
extern  float b11_4;
extern  float b11_5;
extern  float b11_6;
extern  float b11_7;
extern  float b11_8;
extern  float b11_9;
extern  float b11_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = b11_1 * finavalu_temp[0][i];
    float term2 = b11_4 * finavalu_temp[3][i];
    float term3 = b11_5 * finavalu_temp[4][i];
    float term4 = b11_6 * finavalu_temp[5][i];
    float sum1 = term1 + term2;
    float sum2 = term3 + term4;
    float total_inner = sum1 + sum2;
    initvalu_temp[i] = initvalu[i] + h * total_inner;
}
}
