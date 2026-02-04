#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern float *finavalu;
extern  float c_1_11;
extern  float c6;
extern  float c_7_8;
extern  float c_9_10;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float sum1 = finavalu_temp[0][idx] + finavalu_temp[10][idx];
    float sum2 = finavalu_temp[6][idx] + finavalu_temp[7][idx];
    float sum3 = finavalu_temp[8][idx] + finavalu_temp[9][idx];
    float term = h * (c_1_11 * sum1 + c6 * finavalu_temp[5][idx] + c_7_8 * sum2 + c_9_10 * sum3);
    finavalu[idx] = initvalu[idx] + term;
    if (i < 91) {
        finavalu[idx] += h * finavalu_temp[1][idx]; 
    }
}
}
