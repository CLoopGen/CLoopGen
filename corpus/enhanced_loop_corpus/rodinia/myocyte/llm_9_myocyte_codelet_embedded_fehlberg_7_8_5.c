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
    float term1 = b51 * finavalu_temp[0][i];
    float term2 = b53 * finavalu_temp[2][i];
    float term3 = b54 * finavalu_temp[3][i];
    float sum1 = term1 + term2;
    float sum2 = term3 + initvalu[i];
    float product = h * (sum1 + term3);
    initvalu_temp[i] = sum2 + product;
}
}
