#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b31;
extern  float b32;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = h * b31 * finavalu_temp[0][i];
    float term2 = h * b32 * finavalu_temp[1][i];
    float combined = term1 + term2;
    initvalu_temp[i] = initvalu[i] + combined;
    
    float term1b = h * b31 * finavalu_temp[0][90 - i];
    float term2b = h * b32 * finavalu_temp[1][90 - i];
    float combined_b = term1b + term2b;
    initvalu_temp[90 - i] = initvalu[90 - i] + combined_b;
}
}
