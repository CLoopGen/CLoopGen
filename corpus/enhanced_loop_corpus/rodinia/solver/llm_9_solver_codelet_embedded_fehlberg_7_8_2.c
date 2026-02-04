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
    float term1 = h * (b31 * finavalu_temp[0][i] + b32 * finavalu_temp[1][i]);
    float term2 = h * (b31 * finavalu_temp[0][i + 45] + b32 * finavalu_temp[1][i + 45]);
    initvalu_temp[i] = initvalu[i] + term1;
    initvalu_temp[i + 45] = initvalu[i + 45] + term2;
}
}
