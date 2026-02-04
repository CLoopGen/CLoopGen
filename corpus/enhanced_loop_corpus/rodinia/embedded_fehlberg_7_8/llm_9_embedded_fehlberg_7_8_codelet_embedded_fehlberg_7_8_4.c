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
    float c1 = b51 * 1.1f, c2 = b53 * 0.9f, c3 = b54 * 1.05f;
    for (i = 0; i < 45; i++) {
        float term1 = h * (c1 * finavalu_temp[0][i] + c2 * finavalu_temp[2][i] + c3 * finavalu_temp[3][i]);
        float term2 = h * (c1 * finavalu_temp[0][i+45] + c2 * finavalu_temp[2][i+45] + c3 * finavalu_temp[3][i+45]);
        initvalu_temp[i] = initvalu[i] + term1;
        initvalu_temp[i+45] = initvalu[i+45] + term2;
    }
    // Handle remaining index if any (when size is odd or not divisible)
    if (90 < 91) {
        initvalu_temp[90] = initvalu[90] + h * (b51 * finavalu_temp[0][90] + b53 * finavalu_temp[2][90] + b54 * finavalu_temp[3][90]);
    }
}
