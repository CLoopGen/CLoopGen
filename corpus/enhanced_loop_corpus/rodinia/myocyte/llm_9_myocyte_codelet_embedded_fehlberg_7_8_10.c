#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b10_1;
extern  float b10_4;
extern  float b10_5;
extern  float b10_6;
extern  float b10_7;
extern  float b10_8;
extern  float b10_9;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = b10_1 * finavalu_temp[0][i];
    float term2 = b10_4 * finavalu_temp[3][i];
    float term3 = b10_5 * finavalu_temp[4][i];
    float term4 = b10_6 * finavalu_temp[5][i];
    float sum1 = term1 + term2;
    float sum2 = term3 + term4;
    float combined = sum1 + sum2;
    initvalu_temp[i] = initvalu[i] + h * combined;
}
for (i = 45; i < 91; i++) {
    float temp = finavalu_temp[0][i] + finavalu_temp[3][i] - finavalu_temp[4][i];
    initvalu_temp[i] = initvalu[i] + h * (b10_1 * temp + b10_6 * finavalu_temp[5][i] + b10_7 * finavalu_temp[6][i] + b10_8 * finavalu_temp[7][i] + b10_9 * finavalu_temp[8][i]);
}
}
