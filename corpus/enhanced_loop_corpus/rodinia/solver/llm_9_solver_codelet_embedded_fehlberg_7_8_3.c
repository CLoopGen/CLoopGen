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
    float term1 = finavalu_temp[0][i];
    float term2 = finavalu_temp[2][i];
    float combined = b41 * term1 + b43 * term2;
    initvalu_temp[i] = initvalu[i] + h * combined;
    
    float term1b = finavalu_temp[0][90 - i];
    float term2b = finavalu_temp[2][90 - i];
    float combined_b = b41 * term1b + b43 * term2b;
    initvalu_temp[90 - i] = initvalu[90 - i] + h * combined_b;
}
}
