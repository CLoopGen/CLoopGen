#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern float *finavalu;
extern  float c_1_11;
extern  float c6;
extern  float c_7_8;
extern  float c_9_10;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            int idx = i + k;
            finavalu[idx] = initvalu[idx] + h * (c_1_11 * (finavalu_temp[0][idx] + finavalu_temp[10][idx]) + c6 * finavalu_temp[5][idx] + c_7_8 * (finavalu_temp[6][idx] + finavalu_temp[7][idx]) + c_9_10 * (finavalu_temp[8][idx] + finavalu_temp[9][idx]));
        }
    }
}
