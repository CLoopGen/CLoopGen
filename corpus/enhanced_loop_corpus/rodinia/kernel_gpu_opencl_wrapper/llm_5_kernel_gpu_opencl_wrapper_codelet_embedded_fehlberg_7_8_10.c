#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b11_1;
extern  float b11_4;
extern  float b11_5;
extern  float b11_6;
extern  float b11_7;
extern  float b11_8;
extern  float b11_9;
extern  float b11_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i++) {
        float sum = 0.0f;
        if (i < 30) {
            sum += b11_1 * finavalu_temp[0][i];
            sum += b11_4 * finavalu_temp[3][i];
        } else if (i < 60) {
            sum += b11_5 * finavalu_temp[4][i];
            sum += b11_6 * finavalu_temp[5][i];
            sum += b11_7 * finavalu_temp[6][i];
        } else {
            sum += b11_8 * finavalu_temp[7][i];
            sum += b11_9 * finavalu_temp[8][i];
            sum += b11_10 * finavalu_temp[9][i];
        }
        initvalu_temp[i] = initvalu[i] + h * sum;
    }
}
