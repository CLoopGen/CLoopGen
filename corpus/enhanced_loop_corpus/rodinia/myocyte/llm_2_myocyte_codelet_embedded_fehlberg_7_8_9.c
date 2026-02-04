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
for (i = 0; i < 91; i += 3) {
    initvalu_temp[i] = initvalu[i] + h * (b91 * finavalu_temp[0][i] + b94 * finavalu_temp[3][i] + b95 * finavalu_temp[4][i] + b96 * finavalu_temp[5][i] + b97 * finavalu_temp[6][i] + b98 * finavalu_temp[7][i]);
    if (i + 1 < 91) {
        initvalu_temp[i+1] = initvalu[i+1] + h * (b91 * finavalu_temp[0][i+1] + b94 * finavalu_temp[3][i+1] + b95 * finavalu_temp[4][i+1] + b96 * finavalu_temp[5][i+1] + b97 * finavalu_temp[6][i+1] + b98 * finavalu_temp[7][i+1]);
    }
    if (i + 2 < 91) {
        initvalu_temp[i+2] = initvalu[i+2] + h * (b91 * finavalu_temp[0][i+2] + b94 * finavalu_temp[3][i+2] + b95 * finavalu_temp[4][i+2] + b96 * finavalu_temp[5][i+2] + b97 * finavalu_temp[6][i+2] + b98 * finavalu_temp[7][i+2]);
    }
}
}
