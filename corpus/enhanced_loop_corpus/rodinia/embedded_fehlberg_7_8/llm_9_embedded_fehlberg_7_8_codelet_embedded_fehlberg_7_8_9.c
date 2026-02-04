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
    float sum1 = b10_1 * finavalu_temp[0][i];
    float sum2 = b10_1 * finavalu_temp[0][90-i];
    sum1 += b10_4 * finavalu_temp[3][i];
    sum2 += b10_4 * finavalu_temp[3][90-i];
    sum1 += b10_5 * finavalu_temp[4][i];
    sum2 += b10_5 * finavalu_temp[4][90-i];
    sum1 += b10_6 * finavalu_temp[5][i];
    sum2 += b10_6 * finavalu_temp[5][90-i];
    sum1 += b10_7 * finavalu_temp[6][i];
    sum2 += b10_7 * finavalu_temp[6][90-i];
    sum1 += b10_8 * finavalu_temp[7][i];
    sum2 += b10_8 * finavalu_temp[7][90-i];
    sum1 += b10_9 * finavalu_temp[8][i];
    sum2 += b10_9 * finavalu_temp[8][90-i];
    initvalu_temp[i] = initvalu[i] + h * sum1;
    initvalu_temp[90-i] = initvalu[90-i] + h * sum2;
}
}
