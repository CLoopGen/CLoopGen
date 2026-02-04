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
    for (i = 0; i < 91; i++) {
        if (finavalu_temp[0][i] >= 0.0f) {
            initvalu_temp[i] = initvalu[i] + h * (b91 * finavalu_temp[0][i] + b94 * finavalu_temp[3][i] + b95 * finavalu_temp[4][i] + b96 * finavalu_temp[5][i] + b97 * finavalu_temp[6][i] + b98 * finavalu_temp[7][i]);
        } else {
            initvalu_temp[i] = initvalu[i];
        }
    }
}
