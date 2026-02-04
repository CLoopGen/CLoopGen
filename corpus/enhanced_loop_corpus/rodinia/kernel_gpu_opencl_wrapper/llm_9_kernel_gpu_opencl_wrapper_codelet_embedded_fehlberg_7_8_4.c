#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b51;
extern  float b53;
extern  float b54;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float sum1, sum2, sum3, sum4;
for (i = 0; i < 45; i++) {
    sum1 = finavalu_temp[0][i] + finavalu_temp[0][i+45];
    sum2 = finavalu_temp[2][i] + finavalu_temp[2][i+45];
    sum3 = finavalu_temp[3][i] + finavalu_temp[3][i+45];
    sum4 = h * (b51 * sum1 + b53 * sum2 + b54 * sum3);
    initvalu_temp[i]     = initvalu[i]     + sum4;
    initvalu_temp[i+45]  = initvalu[i+45]  + sum4;
}
initvalu_temp[90] = initvalu[90] + h * (b51 * finavalu_temp[0][90] + b53 * finavalu_temp[2][90] + b54 * finavalu_temp[3][90]);
}
