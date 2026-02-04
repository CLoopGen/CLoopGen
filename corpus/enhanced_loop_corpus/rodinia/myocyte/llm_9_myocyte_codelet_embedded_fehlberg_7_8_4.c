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
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float val0 = finavalu_temp[0][idx];
    float val2 = finavalu_temp[2][idx];
    float combined = b41 * val0 + b43 * val2;
    initvalu_temp[idx] = initvalu[idx] + h * combined;
    initvalu_temp[idx] = (initvalu_temp[idx] + initvalu[idx]) * 0.5f;
}
}
