#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b91;
extern  float b94;
extern  float b95;
extern  float b96;
extern  float b97;
extern  float b98;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i++) {
    float temp1 = b91 * finavalu_temp[0][i];
    float temp2 = b94 * finavalu_temp[3][i];
    float temp3 = b95 * finavalu_temp[4][i];
    float temp4 = b96 * finavalu_temp[5][i];
    float temp_sum1 = temp1 + temp2;
    float temp_sum2 = temp3 + temp4;
    float temp5 = b97 * finavalu_temp[6][i];
    float temp6 = b98 * finavalu_temp[7][i];
    float final_inner = temp_sum1 + temp_sum2 + temp5 + temp6;
    initvalu_temp[i] = initvalu[i] + h * final_inner;
}
}
