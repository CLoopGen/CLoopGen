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
    float temp1 = finavalu_temp[0][i] + finavalu_temp[3][i];
    float temp2 = finavalu_temp[4][i] + finavalu_temp[5][i];
    float temp3 = finavalu_temp[6][i] + finavalu_temp[7][i];
    float sum = b91 * temp1 + b94 * finavalu_temp[3][i] + b95 * temp2 + 
                b96 * finavalu_temp[5][i] + b97 * temp3 + b98 * finavalu_temp[7][i];
    initvalu_temp[i] = initvalu[i] + h * sum;
}
}
