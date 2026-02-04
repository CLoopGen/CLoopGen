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
    float prev_val = 0.0f;
    for (i = 0; i < 91; i++) {
        float current_val = initvalu[i] + h * (b31 * finavalu_temp[0][i] + b32 * finavalu_temp[1][i]);
        initvalu_temp[i] = current_val + prev_val;
        prev_val = current_val;
    }
}
