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
    float accumulator = 0.0f;
    for (i = 0; i < 91; i++) {
        accumulator += initvalu[i];
        initvalu_temp[i] = accumulator + h * (b81 * finavalu_temp[0][i] + b85 * finavalu_temp[4][i] + 
                                              b86 * finavalu_temp[5][i] + b87 * finavalu_temp[6][i]);
    }
}
