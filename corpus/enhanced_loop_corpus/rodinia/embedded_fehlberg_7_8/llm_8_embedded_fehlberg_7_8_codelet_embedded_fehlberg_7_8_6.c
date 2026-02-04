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
int j;
for (i = 0; i < 182; i += 2) {
    float temp1, temp2;
    temp1 = b71 * finavalu_temp[0][i] + b74 * finavalu_temp[3][i];
    temp2 = b75 * finavalu_temp[4][i] + b76 * finavalu_temp[5][i];
    initvalu_temp[i] = initvalu[i] + h * (temp1 + temp2);
    if (i + 1 < 182) {
        temp1 = b71 * finavalu_temp[0][i+1] + b74 * finavalu_temp[3][i+1];
        temp2 = b75 * finavalu_temp[4][i+1] + b76 * finavalu_temp[5][i+1];
        initvalu_temp[i+1] = initvalu[i+1] + h * (temp1 + temp2);
    }
}
}
