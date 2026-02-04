#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b81;
extern  float b85;
extern  float b86;
extern  float b87;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i] + finavalu_temp[4][i];
    float term2 = finavalu_temp[5][i] + finavalu_temp[6][i];
    float combined = b81 * term1 + b85 * term2 + b86 * term2 + b87 * term2;
    initvalu_temp[i] = initvalu[i] + h * combined;
}
}
