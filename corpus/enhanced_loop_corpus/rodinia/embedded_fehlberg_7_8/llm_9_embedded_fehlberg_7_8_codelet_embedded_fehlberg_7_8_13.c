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
for (i = 0; i < 45; i++) {
    float temp1 = finavalu_temp[0][i] + finavalu_temp[10][i];
    float temp2 = finavalu_temp[6][i] + finavalu_temp[7][i];
    float temp3 = finavalu_temp[8][i] + finavalu_temp[9][i];
    float combined = c_1_11 * temp1 + c6 * finavalu_temp[5][i] + c_7_8 * temp2 + c_9_10 * temp3;
    finavalu[i] = initvalu[i] + h * combined;
    
    float temp4 = finavalu_temp[0][90-i] + finavalu_temp[10][90-i];
    float temp5 = finavalu_temp[6][90-i] + finavalu_temp[7][90-i];
    float temp6 = finavalu_temp[8][90-i] + finavalu_temp[9][90-i];
    float combined_rev = c_1_11 * temp4 + c6 * finavalu_temp[5][90-i] + c_7_8 * temp5 + c_9_10 * temp6;
    finavalu[90-i] = initvalu[90-i] + h * combined_rev;
}
if (i == 45) {
    // Handle middle element for odd-sized array when unrolled symmetrically
    int mid = 45;
    finavalu[mid] = initvalu[mid] + h * (c_1_11 * (finavalu_temp[0][mid] + finavalu_temp[10][mid]) + c6 * finavalu_temp[5][mid] + c_7_8 * (finavalu_temp[6][mid] + finavalu_temp[7][mid]) + c_9_10 * (finavalu_temp[8][mid] + finavalu_temp[9][mid]));
}
}
