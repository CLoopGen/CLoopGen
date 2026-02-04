#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern float *finavalu;
extern  float c_1_11;
extern  float c6;
extern  float c_7_8;
extern  float c_9_10;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i += 2) {
    float temp1 = finavalu_temp[0][i] + finavalu_temp[10][i];
    float temp2 = finavalu_temp[6][i] + finavalu_temp[7][i];
    float temp3 = finavalu_temp[8][i] + finavalu_temp[9][i];
    finavalu[i] = initvalu[i] + h * (c_1_11 * temp1 + c6 * finavalu_temp[5][i] + c_7_8 * temp2 + c_9_10 * temp3);
}
}
