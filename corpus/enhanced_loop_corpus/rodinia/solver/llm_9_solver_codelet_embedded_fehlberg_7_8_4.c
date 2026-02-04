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
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i];
    float term2 = finavalu_temp[2][i];
    float term3 = finavalu_temp[3][i];
    float combined = b51 * term1 + b53 * term2 + b54 * term3;
    initvalu_temp[i] = initvalu[i] + h * combined;
    initvalu_temp[90 - i] = initvalu[90 - i] + h * (b51 * finavalu_temp[0][90 - i] + b53 * finavalu_temp[2][90 - i] + b54 * finavalu_temp[3][90 - i]);
}
}
