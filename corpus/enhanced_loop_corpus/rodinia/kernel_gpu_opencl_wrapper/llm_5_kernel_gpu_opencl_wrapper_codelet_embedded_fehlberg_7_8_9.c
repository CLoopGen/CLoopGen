#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b10_1;
extern  float b10_4;
extern  float b10_5;
extern  float b10_6;
extern  float b10_7;
extern  float b10_8;
extern  float b10_9;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i++) {
        float sum = 0.0f;
        if (i < 30) {
            sum += b10_1 * finavalu_temp[0][i];
            sum += b10_4 * finavalu_temp[3][i];
        } else if (i < 60) {
            sum += b10_5 * finavalu_temp[4][i];
            sum += b10_6 * finavalu_temp[5][i];
            sum += b10_7 * finavalu_temp[6][i];
        } else {
            sum += b10_8 * finavalu_temp[7][i];
            sum += b10_9 * finavalu_temp[8][i];
        }
        initvalu_temp[i] = initvalu[i] + h * sum;
    }
}
