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
int indices[91];
for (int j = 0; j < 91; j++) {
    indices[j] = 90 - j; // reverse access pattern
}
for (i = 0; i < 91; i++) {
    int idx = indices[i];
    initvalu_temp[idx] = initvalu[idx] + h * (b31 * finavalu_temp[0][idx] + b32 * finavalu_temp[1][idx]);
}
}
