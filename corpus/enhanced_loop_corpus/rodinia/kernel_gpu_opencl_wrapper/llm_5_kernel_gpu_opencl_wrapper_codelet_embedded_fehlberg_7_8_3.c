#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b41;
extern  float b43;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i++) {
    float temp_val = 0.0f;
    if (i % 2 == 0) {
        temp_val = b41 * finavalu_temp[0][i];
    } else {
        temp_val = b43 * finavalu_temp[2][i];
    }
    initvalu_temp[i] = initvalu[i] + h * temp_val;
}
}
