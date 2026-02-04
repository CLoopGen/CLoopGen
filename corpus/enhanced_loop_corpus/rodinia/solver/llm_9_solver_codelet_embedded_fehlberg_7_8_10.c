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
for (i = 0; i < 182; i++) {
    float temp_sum1 = b11_1 * finavalu_temp[0][i % 91];
    float temp_sum2 = b11_4 * finavalu_temp[3][i % 91] + b11_5 * finavalu_temp[4][i % 91];
    float temp_sum3 = b11_6 * finavalu_temp[5][i % 91] + b11_7 * finavalu_temp[6][i % 91];
    float temp_sum4 = b11_8 * finavalu_temp[7][i % 91] + b11_9 * finavalu_temp[8][i % 91];
    float temp_sum5 = b11_10 * finavalu_temp[9][i % 91];
    initvalu_temp[i % 91] = initvalu[i % 91] + h * (temp_sum1 + temp_sum2 + temp_sum3 + temp_sum4 + temp_sum5);
}
}
