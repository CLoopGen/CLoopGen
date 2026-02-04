#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b13_1;
extern  float b13_4;
extern  float b13_5;
extern  float b13_6;
extern  float b13_7;
extern  float b13_8;
extern  float b13_9;
extern  float b13_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i] + finavalu_temp[3][i];
    float term2 = finavalu_temp[4][i] + finavalu_temp[5][i];
    float term3 = finavalu_temp[6][i] + finavalu_temp[7][i];
    float term4 = finavalu_temp[8][i] + finavalu_temp[9][i];
    float combined = b13_1 * term1 + b13_4 * term2 + b13_5 * term2 + b13_6 * term3 + b13_7 * term3 + b13_8 * term4 + b13_9 * term4 + b13_10 * finavalu_temp[9][i] + finavalu_temp[11][i];
    initvalu_temp[i] = initvalu[i] + h * combined;
}
}
