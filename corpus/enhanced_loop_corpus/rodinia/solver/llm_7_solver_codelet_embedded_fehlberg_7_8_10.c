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
        float accumulator = finavalu_temp[0][i] * b11_1;
        accumulator += finavalu_temp[3][i] * b11_4;
        accumulator += finavalu_temp[4][i] * b11_5;
        accumulator += finavalu_temp[5][i] * b11_6;
        accumulator += finavalu_temp[6][i] * b11_7;
        accumulator += finavalu_temp[7][i] * b11_8;
        accumulator += finavalu_temp[8][i] * b11_9;
        accumulator += finavalu_temp[9][i] * b11_10;
        initvalu_temp[i] = initvalu[i] + h * accumulator;
    }
}
