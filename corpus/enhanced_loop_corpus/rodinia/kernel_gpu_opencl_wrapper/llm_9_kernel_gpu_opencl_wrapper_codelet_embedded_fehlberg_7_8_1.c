#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float h2_7;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float temp1 = finavalu_temp[0][i] * h2_7;
    float temp2 = finavalu_temp[0][90 - i] * h2_7;
    initvalu_temp[i] = initvalu[i] + temp1;
    initvalu_temp[90 - i] = initvalu[90 - i] + temp2;
}
}
