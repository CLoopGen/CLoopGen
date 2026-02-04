#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b81;
extern  float b85;
extern  float b86;
extern  float b87;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i += 2) {
    initvalu_temp[i] = initvalu[i] + h * (b81 * finavalu_temp[0][i]);
    if (i + 1 < 45) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b81 * finavalu_temp[0][i+1] + b85 * finavalu_temp[4][i+1]);
    }
}
}
