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
for (i = 0; i < 91; i++) {
    float temp_sum = 0.0f;
    if (i < 30) {
        temp_sum += c_1_11 * (finavalu_temp[0][i] + finavalu_temp[10][i]);
        temp_sum += c6 * finavalu_temp[5][i];
    } else if (i < 60) {
        temp_sum += c_7_8 * (finavalu_temp[6][i] + finavalu_temp[7][i]);
    } else {
        temp_sum += c_9_10 * (finavalu_temp[8][i] + finavalu_temp[9][i]);
    }
    finavalu[i] = initvalu[i] + h * temp_sum;
}
}
