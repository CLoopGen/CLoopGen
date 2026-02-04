#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b71;
extern  float b74;
extern  float b75;
extern  float b76;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            int idx = i + k;
            initvalu_temp[idx] = initvalu[idx] + h * (b71 * finavalu_temp[0][idx] + b74 * finavalu_temp[3][idx] + b75 * finavalu_temp[4][idx] + b76 * finavalu_temp[5][idx]);
        }
    }
}
