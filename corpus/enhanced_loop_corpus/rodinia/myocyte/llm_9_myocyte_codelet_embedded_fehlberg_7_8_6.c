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
    float term1 = h * b61 * finavalu_temp[0][i];
    float term2 = h * b64 * finavalu_temp[3][i];
    float term3 = h * b65 * finavalu_temp[4][i];
    initvalu_temp[i] = initvalu[i] + term1 + term2 + term3;
    
    float term4 = h * b61 * finavalu_temp[0][i + 45];
    float term5 = h * b64 * finavalu_temp[3][i + 45];
    float term6 = h * b65 * finavalu_temp[4][i + 45];
    initvalu_temp[i + 45] = initvalu[i + 45] + term4 + term5 + term6;
}
initvalu_temp[90] = initvalu[90] + h * (b61 * finavalu_temp[0][90] + b64 * finavalu_temp[3][90] + b65 * finavalu_temp[4][90]);
}
