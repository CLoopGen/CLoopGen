#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b11_1;
extern  float b11_4;
extern  float b11_5;
extern  float b11_6;
extern  float b11_7;
extern  float b11_8;
extern  float b11_9;
extern  float b11_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i++) {
    float temp_sum = 0.0f;
    if (i >= 10) {
        temp_sum += b11_1 * finavalu_temp[0][i];
    }
    if (i >= 20) {
        temp_sum += b11_4 * finavalu_temp[3][i];
    }
    if (i >= 30) {
        temp_sum += b11_5 * finavalu_temp[4][i];
    }
    if (i >= 40) {
        temp_sum += b11_6 * finavalu_temp[5][i];
    }
    if (i >= 50) {
        temp_sum += b11_7 * finavalu_temp[6][i];
    }
    if (i >= 60) {
        temp_sum += b11_8 * finavalu_temp[7][i];
    }
    if (i >= 70) {
        temp_sum += b11_9 * finavalu_temp[8][i];
    }
    if (i >= 80) {
        temp_sum += b11_10 * finavalu_temp[9][i];
    }
    initvalu_temp[i] = initvalu[i] + h * temp_sum;
}
}
