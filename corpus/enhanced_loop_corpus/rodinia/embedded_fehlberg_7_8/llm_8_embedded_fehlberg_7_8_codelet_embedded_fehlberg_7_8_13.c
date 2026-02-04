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
int j;
for (i = 0; i < 182; i += 2) {
    if (i + 1 < 91) {
        finavalu[i] = initvalu[i] + h * (c_1_11 * finavalu_temp[0][i] + c6 * finavalu_temp[5][i] + c_7_8 * finavalu_temp[6][i] + c_9_10 * finavalu_temp[8][i]);
        finavalu[i+1] = initvalu[i+1] + h * (c_1_11 * finavalu_temp[10][i+1] + c6 * finavalu_temp[5][i+1] + c_7_8 * finavalu_temp[7][i+1] + c_9_10 * finavalu_temp[9][i+1]);
    }
    else if (i < 91) {
        finavalu[i] = initvalu[i] + h * (c_1_11 * (finavalu_temp[0][i] + finavalu_temp[10][i]) + c6 * finavalu_temp[5][i] + c_7_8 * (finavalu_temp[6][i] + finavalu_temp[7][i]) + c_9_10 * (finavalu_temp[8][i] + finavalu_temp[9][i]));
    }
}
}
