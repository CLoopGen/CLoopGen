#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b61;
extern  float b64;
extern  float b65;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float term1 = b61 * finavalu_temp[0][i];
    float term2 = b64 * finavalu_temp[3][i];
    float term3 = b65 * finavalu_temp[4][i];
    float combined = h * (term1 + term2 + term3);
    initvalu_temp[i] = initvalu[i] + combined;
    
    float term1b = b61 * finavalu_temp[0][90 - i];
    float term2b = b64 * finavalu_temp[3][90 - i];
    float term3b = b65 * finavalu_temp[4][90 - i];
    float combined_b = h * (term1b + term2b + term3b);
    initvalu_temp[90 - i] = initvalu[90 - i] + combined_b;
}
}
