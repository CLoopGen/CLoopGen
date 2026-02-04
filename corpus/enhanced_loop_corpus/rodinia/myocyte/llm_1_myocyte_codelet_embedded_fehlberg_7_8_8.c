#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b81;
extern  float b85;
extern  float b86;
extern  float b87;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int j = 0; j < 3 && (i + j) < 91; j++) {
            int idx = i + j;
            initvalu_temp[idx] = initvalu[idx] + h * (b81 * finavalu_temp[0][idx] + b85 * finavalu_temp[4][idx] + b86 * finavalu_temp[5][idx] + b87 * finavalu_temp[6][idx]);
        }
    }
}
