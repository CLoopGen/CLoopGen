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
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float temp1 = finavalu_temp[0][idx] + finavalu_temp[3][idx] + finavalu_temp[4][idx];
    float temp2 = finavalu_temp[5][idx] + finavalu_temp[6][idx] + finavalu_temp[7][idx];
    float temp3 = finavalu_temp[8][idx] + finavalu_temp[9][idx] + finavalu_temp[11][idx];
    initvalu_temp[idx] = initvalu[idx] + h * (b13_1 * temp1 + b13_4 * temp1 + b13_5 * temp1 +
                                              b13_6 * temp2 + b13_7 * temp2 + b13_8 * temp2 +
                                              b13_9 * temp3 + b13_10 * temp3 + temp3 - 
                                              (b13_4 + b13_5 + b13_6 + b13_7 + b13_8 + b13_9 + b13_10 - 1.0f) * finavalu_temp[11][idx]);
}
}
