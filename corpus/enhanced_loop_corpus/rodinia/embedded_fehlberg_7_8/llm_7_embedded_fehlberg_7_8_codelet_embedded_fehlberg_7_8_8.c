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
    for (i = 1; i < 91; i++) {
        initvalu_temp[i] = initvalu[i] + h * (
            b91 * finavalu_temp[0][i-1] + 
            b94 * finavalu_temp[3][i-1] + 
            b95 * finavalu_temp[4][i-1] + 
            b96 * finavalu_temp[5][i-1] + 
            b97 * finavalu_temp[6][i-1] + 
            b98 * finavalu_temp[7][i-1]
        );
    }
    if (91 > 0) {
        initvalu_temp[0] = initvalu[0] + h * (
            b91 * finavalu_temp[0][0] + 
            b94 * finavalu_temp[3][0] + 
            b95 * finavalu_temp[4][0] + 
            b96 * finavalu_temp[5][0] + 
            b97 * finavalu_temp[6][0] + 
            b98 * finavalu_temp[7][0]
        );
    }
}
