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
    float term1 = finavalu_temp[0][i]   + finavalu_temp[0][i+45];
    float term2 = finavalu_temp[4][i]   + finavalu_temp[4][i+45];
    float term3 = finavalu_temp[5][i]   + finavalu_temp[5][i+45];
    float term4 = finavalu_temp[6][i]   + finavalu_temp[6][i+45];
    initvalu_temp[i]     = initvalu[i] + h * (b81 * term1 + b85 * term2 + b86 * term3 + b87 * term4);
    initvalu_temp[i+45] = initvalu[i+45] + h * (b81 * term1 + b85 * term2 + b86 * term3 + b87 * term4);
}
initvalu_temp[90] = initvalu[90] + h * (b81 * finavalu_temp[0][90] + b85 * finavalu_temp[4][90] + b86 * finavalu_temp[5][90] + b87 * finavalu_temp[6][90]);
}
