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
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            int idx = i + k;
            initvalu_temp[idx] = initvalu[idx] + h * (b12_1 * finavalu_temp[0][idx] + b12_6 * finavalu_temp[5][idx] + b12_7 * finavalu_temp[6][idx] + b12_8 * finavalu_temp[7][idx] + b12_9 * finavalu_temp[8][idx] + b12_10 * finavalu_temp[9][idx]);
        }
    }
}
