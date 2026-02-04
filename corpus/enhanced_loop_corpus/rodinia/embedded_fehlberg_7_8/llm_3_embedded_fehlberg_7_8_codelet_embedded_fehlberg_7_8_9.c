#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b10_1;
extern  float b10_4;
extern  float b10_5;
extern  float b10_6;
extern  float b10_7;
extern  float b10_8;
extern  float b10_9;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[91];
for (int j = 0; j < 91; j++) {
    indices[j] = 90 - j; // reverse access pattern: indirect and non-consecutive in logical order
}
for (i = 0; i < 91; i++) {
    int idx = indices[i];
    initvalu_temp[idx] = initvalu[idx] + h * (b10_1 * finavalu_temp[0][idx] + b10_4 * finavalu_temp[3][idx] + b10_5 * finavalu_temp[4][idx] + b10_6 * finavalu_temp[5][idx] + b10_7 * finavalu_temp[6][idx] + b10_8 * finavalu_temp[7][idx] + b10_9 * finavalu_temp[8][idx]);
}
}
