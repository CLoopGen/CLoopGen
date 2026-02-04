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
    for (i = 0; i < 91; i++) {
        float temp_val = 0.0f;
        if (i % 2 == 0) {
            temp_val = b81 * finavalu_temp[0][i];
        } else {
            temp_val = b85 * finavalu_temp[4][i] + b86 * finavalu_temp[5][i];
        }
        initvalu_temp[i] = initvalu[i] + h * (temp_val + b87 * finavalu_temp[6][i]);
    }
}
