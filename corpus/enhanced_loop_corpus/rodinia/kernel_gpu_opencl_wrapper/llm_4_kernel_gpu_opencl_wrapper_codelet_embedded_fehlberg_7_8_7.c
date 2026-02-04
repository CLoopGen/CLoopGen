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
        if (finavalu_temp[0][i] >= 0.0f) {
            initvalu_temp[i] = initvalu[i] + h * (b81 * finavalu_temp[0][i] + b85 * finavalu_temp[4][i] + b86 * finavalu_temp[5][i] + b87 * finavalu_temp[6][i]);
        } else {
            initvalu_temp[i] = initvalu[i];
        }
    }
}
