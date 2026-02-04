#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b12_1;
extern  float b12_6;
extern  float b12_7;
extern  float b12_8;
extern  float b12_9;
extern  float b12_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i += 2) {
    float temp1 = finavalu_temp[0][i] + finavalu_temp[5][i] * (b12_6 / b12_1);
    float temp2 = finavalu_temp[6][i] + finavalu_temp[7][i] * (b12_8 / b12_7);
    float temp3 = finavalu_temp[8][i] * b12_9 + finavalu_temp[9][i] * b12_10;
    initvalu_temp[i] = initvalu[i] + h * (b12_1 * temp1 + b12_7 * temp2 + temp3);
}
}
