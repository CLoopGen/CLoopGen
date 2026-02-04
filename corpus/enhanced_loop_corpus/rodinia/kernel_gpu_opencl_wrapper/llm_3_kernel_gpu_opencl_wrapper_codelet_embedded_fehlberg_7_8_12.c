#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b13_1;
extern  float b13_4;
extern  float b13_5;
extern  float b13_6;
extern  float b13_7;
extern  float b13_8;
extern  float b13_9;
extern  float b13_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[91];
for (int k = 0; k < 91; k++) {
    indices[k] = 90 - k; // reverse access pattern
}
for (i = 0; i < 91; i++) {
    int idx = indices[i];
    initvalu_temp[idx] = initvalu[idx] + h * (b13_1 * finavalu_temp[0][idx] + b13_4 * finavalu_temp[3][idx] + b13_5 * finavalu_temp[4][idx] + b13_6 * finavalu_temp[5][idx] + b13_7 * finavalu_temp[6][idx] + b13_8 * finavalu_temp[7][idx] + b13_9 * finavalu_temp[8][idx] + b13_10 * finavalu_temp[9][idx] + finavalu_temp[11][idx]);
}
}
