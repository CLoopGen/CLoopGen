#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b51;
extern  float b53;
extern  float b54;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 182; i += 2) {
    initvalu_temp[i] = initvalu[i] + h * (b51 * finavalu_temp[0][i] + b53 * finavalu_temp[2][i] + b54 * finavalu_temp[3][i]);
    if (i + 1 < 91) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b51 * finavalu_temp[0][i+1] + b53 * finavalu_temp[2][i+1] + b54 * finavalu_temp[3][i+1]);
    }
}
}
