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
for (i = 0; i < 91; i += 4) {
    initvalu_temp[i] = initvalu[i] + h * (b81 * finavalu_temp[0][i] + b85 * finavalu_temp[4][i] + b86 * finavalu_temp[5][i] + b87 * finavalu_temp[6][i]);
    if (i + 1 < 91)
        initvalu_temp[i+1] = initvalu[i+1] + h * (b81 * finavalu_temp[0][i+1] + b85 * finavalu_temp[4][i+1] + b86 * finavalu_temp[5][i+1] + b87 * finavalu_temp[6][i+1]);
    if (i + 2 < 91)
        initvalu_temp[i+2] = initvalu[i+2] + h * (b81 * finavalu_temp[0][i+2] + b85 * finavalu_temp[4][i+2] + b86 * finavalu_temp[5][i+2] + b87 * finavalu_temp[6][i+2]);
    if (i + 3 < 91)
        initvalu_temp[i+3] = initvalu[i+3] + h * (b81 * finavalu_temp[0][i+3] + b85 * finavalu_temp[4][i+3] + b86 * finavalu_temp[5][i+3] + b87 * finavalu_temp[6][i+3]);
}
}
