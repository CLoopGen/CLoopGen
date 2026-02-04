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
for (i = 0; i < 91; i += 4) {
    initvalu_temp[i] = initvalu[i] + h * (b71 * finavalu_temp[0][i] + b74 * finavalu_temp[3][i] + b75 * finavalu_temp[4][i] + b76 * finavalu_temp[5][i]);
    if (i + 1 < 91)
        initvalu_temp[i+1] = initvalu[i+1] + h * (b71 * finavalu_temp[0][i+1] + b74 * finavalu_temp[3][i+1] + b75 * finavalu_temp[4][i+1] + b76 * finavalu_temp[5][i+1]);
    if (i + 2 < 91)
        initvalu_temp[i+2] = initvalu[i+2] + h * (b71 * finavalu_temp[0][i+2] + b74 * finavalu_temp[3][i+2] + b75 * finavalu_temp[4][i+2] + b76 * finavalu_temp[5][i+2]);
    if (i + 3 < 91)
        initvalu_temp[i+3] = initvalu[i+3] + h * (b71 * finavalu_temp[0][i+3] + b74 * finavalu_temp[3][i+3] + b75 * finavalu_temp[4][i+3] + b76 * finavalu_temp[5][i+3]);
}
}
