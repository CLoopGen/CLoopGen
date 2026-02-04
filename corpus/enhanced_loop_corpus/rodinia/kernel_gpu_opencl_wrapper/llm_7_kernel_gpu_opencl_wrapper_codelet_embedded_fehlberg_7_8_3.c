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
    float acc = 0.0f;
    for (i = 0; i < 91; i++) {
        acc += initvalu[i];
        initvalu_temp[i] = acc + h * (b41 * finavalu_temp[0][i] + b43 * finavalu_temp[2][i]);
    }
}
