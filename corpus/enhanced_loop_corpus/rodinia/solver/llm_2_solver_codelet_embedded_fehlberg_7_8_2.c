#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b31;
extern  float b32;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i += 3) {
    initvalu_temp[i] = initvalu[i] + h * (b31 * finavalu_temp[0][i] + b32 * finavalu_temp[1][i]);
    if (i+1 < 91) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b31 * finavalu_temp[0][i+1] + b32 * finavalu_temp[1][i+1]);
    }
    if (i+2 < 91) {
        initvalu_temp[i+2] = initvalu[i+2] + h * (b31 * finavalu_temp[0][i+2] + b32 * finavalu_temp[1][i+2]);
    }
}
}
