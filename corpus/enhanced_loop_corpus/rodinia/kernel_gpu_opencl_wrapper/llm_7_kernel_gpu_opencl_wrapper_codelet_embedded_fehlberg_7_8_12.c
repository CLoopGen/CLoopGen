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
    for (i = 0; i < 91; i++) {
        float accumulator = finavalu_temp[11][i];
        accumulator += b13_1 * finavalu_temp[0][i];
        accumulator += b13_4 * finavalu_temp[3][i];
        accumulator += b13_5 * finavalu_temp[4][i];
        accumulator += b13_6 * finavalu_temp[5][i];
        accumulator += b13_7 * finavalu_temp[6][i];
        accumulator += b13_8 * finavalu_temp[7][i];
        accumulator += b13_9 * finavalu_temp[8][i];
        accumulator += b13_10 * finavalu_temp[9][i];
        initvalu_temp[i] = initvalu[i] + h * accumulator;
    }
}
