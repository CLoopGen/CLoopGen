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
for (i = 0; i < 182; i++) {
    float sum1 = (i % 2 == 0) ? 
        (b10_1 * finavalu_temp[0][i % 91] + b10_4 * finavalu_temp[3][i % 91]) : 
        (b10_5 * finavalu_temp[4][i % 91] + b10_6 * finavalu_temp[5][i % 91]);
    float sum2 = (i % 3 == 0) ? 
        (b10_7 * finavalu_temp[6][i % 91]) : 
        (b10_8 * finavalu_temp[7][i % 91] + b10_9 * finavalu_temp[8][i % 91]);
    initvalu_temp[i % 91] += h * (sum1 + sum2);
}
}
