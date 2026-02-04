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
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float sum = 0.0f;
    for (int k = 0; k < 3; k++) {
        sum += finavalu_temp[k][idx] + finavalu_temp[10 - k][idx];
    }
    finavalu[idx] = initvalu[idx] + h * (c_1_11 * sum + c6 * finavalu_temp[5][idx]);
}
}
