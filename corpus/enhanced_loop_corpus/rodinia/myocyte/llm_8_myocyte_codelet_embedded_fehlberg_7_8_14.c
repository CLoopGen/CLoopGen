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
    if (i + 1 < 45) {
        float temp1_next = finavalu_temp[0][i+1] + finavalu_temp[10][i+1];
        float temp2_next = finavalu_temp[6][i+1] + finavalu_temp[7][i+1];
        float temp3_next = finavalu_temp[8][i+1] + finavalu_temp[9][i+1];
        finavalu[i+1] = initvalu[i+1] + h * (c_1_11 * temp1_next + c6 * finavalu_temp[5][i+1] + c_7_8 * temp2_next + c_9_10 * temp3_next);
    }
}
}
