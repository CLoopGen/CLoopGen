#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b91;
extern  float b94;
extern  float b95;
extern  float b96;
extern  float b97;
extern  float b98;
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
    initvalu_temp[idx] = initvalu[idx] + h * (b91 * finavalu_temp[0][idx] + b94 * finavalu_temp[3][idx] + b95 * finavalu_temp[4][idx] + b96 * finavalu_temp[5][idx] + b97 * finavalu_temp[6][idx] + b98 * finavalu_temp[7][idx]);
}
}
