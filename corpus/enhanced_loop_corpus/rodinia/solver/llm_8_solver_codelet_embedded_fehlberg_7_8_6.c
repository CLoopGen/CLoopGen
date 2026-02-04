#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b71;
extern  float b74;
extern  float b75;
extern  float b76;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 182; i += 2) {
    initvalu_temp[i] = initvalu[i] + h * (b71 * finavalu_temp[0][i] + b74 * finavalu_temp[3][i] + b75 * finavalu_temp[4][i]);
    if (i + 1 < 91) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b71 * finavalu_temp[0][i+1] + b76 * finavalu_temp[5][i+1]);
    }
}
}
