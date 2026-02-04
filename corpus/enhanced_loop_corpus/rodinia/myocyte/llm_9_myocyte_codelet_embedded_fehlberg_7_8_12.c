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
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i] + finavalu_temp[5][i];
    float term2 = finavalu_temp[6][i] + finavalu_temp[7][i];
    float term3 = finavalu_temp[8][i] + finavalu_temp[9][i];
    float combined = b12_1 * term1 + b12_6 * finavalu_temp[5][i] + b12_7 * term2 + b12_8 * term2 + b12_9 * term3 + b12_10 * finavalu_temp[9][i];
    initvalu_temp[i] = initvalu[i] + h * combined;
}
}
