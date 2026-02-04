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
for (i = 0; i < 91; i += 4) {
    int j = i;
    if (j < 91) finavalu[j] = initvalu[j] + h * (c_1_11 * (finavalu_temp[0][j] + finavalu_temp[10][j]) + c6 * finavalu_temp[5][j] + c_7_8 * (finavalu_temp[6][j] + finavalu_temp[7][j]) + c_9_10 * (finavalu_temp[8][j] + finavalu_temp[9][j]));
    j = i + 1;
    if (j < 91) finavalu[j] = initvalu[j] + h * (c_1_11 * (finavalu_temp[0][j] + finavalu_temp[10][j]) + c6 * finavalu_temp[5][j] + c_7_8 * (finavalu_temp[6][j] + finavalu_temp[7][j]) + c_9_10 * (finavalu_temp[8][j] + finavalu_temp[9][j]));
    j = i + 2;
    if (j < 91) finavalu[j] = initvalu[j] + h * (c_1_11 * (finavalu_temp[0][j] + finavalu_temp[10][j]) + c6 * finavalu_temp[5][j] + c_7_8 * (finavalu_temp[6][j] + finavalu_temp[7][j]) + c_9_10 * (finavalu_temp[8][j] + finavalu_temp[9][j]));
    j = i + 3;
    if (j < 91) finavalu[j] = initvalu[j] + h * (c_1_11 * (finavalu_temp[0][j] + finavalu_temp[10][j]) + c6 * finavalu_temp[5][j] + c_7_8 * (finavalu_temp[6][j] + finavalu_temp[7][j]) + c_9_10 * (finavalu_temp[8][j] + finavalu_temp[9][j]));
}
}
