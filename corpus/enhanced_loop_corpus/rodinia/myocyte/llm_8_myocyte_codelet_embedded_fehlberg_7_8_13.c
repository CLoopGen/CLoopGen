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
for (i = 0; i < 182; i += 2) {
    initvalu_temp[i] = initvalu[i] + h * (b13_1 * finavalu_temp[0][i] + b13_4 * finavalu_temp[3][i] + b13_5 * finavalu_temp[4][i] + b13_6 * finavalu_temp[5][i]);
    if (i + 1 < 182) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b13_7 * finavalu_temp[6][i+1] + b13_8 * finavalu_temp[7][i+1] + b13_9 * finavalu_temp[8][i+1] + b13_10 * finavalu_temp[9][i+1] + finavalu_temp[11][i+1]);
    }
}
}
