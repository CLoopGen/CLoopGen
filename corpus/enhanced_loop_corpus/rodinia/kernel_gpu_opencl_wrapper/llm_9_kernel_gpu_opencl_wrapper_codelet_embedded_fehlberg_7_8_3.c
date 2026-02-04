#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b41;
extern  float b43;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = h * b41 * finavalu_temp[0][i];
    float term2 = h * b43 * finavalu_temp[2][i];
    float combined = term1 + term2;
    initvalu_temp[i] = initvalu[i] + combined;
    
    float term1_alt = h * b41 * finavalu_temp[0][90 - i];
    float term2_alt = h * b43 * finavalu_temp[2][90 - i];
    initvalu_temp[90 - i] = initvalu[90 - i] + term1_alt + term2_alt;
}
}
