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
    float term1 = finavalu_temp[0][i] + finavalu_temp[3][i];
    float term2 = finavalu_temp[4][i] - finavalu_temp[5][i];
    float combined = b71 * term1 + b74 * finavalu_temp[3][i] + b75 * term2 + b76 * finavalu_temp[5][i];
    initvalu_temp[i] = initvalu[i] + h * combined;
    initvalu_temp[90 - i] = initvalu[90 - i] + h * (b71 * finavalu_temp[0][90 - i]);
}
}
