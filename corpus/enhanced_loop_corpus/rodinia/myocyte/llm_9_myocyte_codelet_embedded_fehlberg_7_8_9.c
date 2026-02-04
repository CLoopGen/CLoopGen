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
for (i = 0; i < 45; i++) {
    float term1 = finavalu_temp[0][i]   * b91 + finavalu_temp[3][i]   * b94;
    float term2 = finavalu_temp[4][i+46] * b95 + finavalu_temp[5][i+46] * b96;
    float term3 = finavalu_temp[6][i]   * b97 + finavalu_temp[7][i]   * b98;
    initvalu_temp[i] = initvalu[i] + h * (term1 + term2 + term3);
}
}
