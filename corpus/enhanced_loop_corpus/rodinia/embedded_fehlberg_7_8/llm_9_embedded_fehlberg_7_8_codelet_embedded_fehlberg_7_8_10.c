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
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float sum = b11_1 * finavalu_temp[0][idx];
    if (i % 3 == 0) {
        sum += b11_4 * finavalu_temp[3][idx];
    }
    if (i % 5 == 0) {
        sum += b11_5 * finavalu_temp[4][idx];
    }
    sum += b11_6 * finavalu_temp[5][idx];
    sum += b11_7 * finavalu_temp[6][idx];
    if (i < 130) {
        sum += b11_8 * finavalu_temp[7][idx];
    }
    if (i > 50) {
        sum += b11_9 * finavalu_temp[8][idx];
    }
    if (i % 7 == 0) {
        sum += b11_10 * finavalu_temp[9][idx];
    }
    initvalu_temp[idx] = initvalu[idx] + h * sum;
}
}
