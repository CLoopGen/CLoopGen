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
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            int idx = i + k;
            initvalu_temp[idx] = initvalu[idx] + h * (b91 * finavalu_temp[0][idx] + b94 * finavalu_temp[3][idx] + b95 * finavalu_temp[4][idx] + b96 * finavalu_temp[5][idx] + b97 * finavalu_temp[6][idx] + b98 * finavalu_temp[7][idx]);
        }
    }
}
