#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b12_1;
extern  float b12_6;
extern  float b12_7;
extern  float b12_8;
extern  float b12_9;
extern  float b12_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float accumulator = 0.0f;
    for (i = 0; i < 91; i++) {
        if (i > 0) {
            initvalu_temp[i] = initvalu[i] + h * (b12_1 * finavalu_temp[0][i-1] + 
                                                  b12_6 * finavalu_temp[5][i-1] + 
                                                  b12_7 * finavalu_temp[6][i-1] + 
                                                  b12_8 * finavalu_temp[7][i-1] + 
                                                  b12_9 * finavalu_temp[8][i-1] + 
                                                  b12_10 * finavalu_temp[9][i-1]);
        } else {
            initvalu_temp[i] = initvalu[i];
        }
        accumulator += initvalu_temp[i];
    }
    // Use accumulator to prevent dead code elimination
    initvalu_temp[0] += accumulator * 0.0f;
}
