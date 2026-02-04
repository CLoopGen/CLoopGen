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
    float term1 = h * b61 * (finavalu_temp[0][i] + finavalu_temp[0][i+45]);
    float term2 = h * b64 * (finavalu_temp[3][i] + finavalu_temp[3][i+45]);
    float term3 = h * b65 * (finavalu_temp[4][i] + finavalu_temp[4][i+45]);
    initvalu_temp[i] = initvalu[i] + term1 + term2 + term3;
    initvalu_temp[i+45] = initvalu[i+45] + term1 + term2 + term3;
}
}
