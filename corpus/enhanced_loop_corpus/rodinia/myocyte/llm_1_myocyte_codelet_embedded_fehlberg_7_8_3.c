#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b31;
extern  float b32;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            int idx = i + k;
            initvalu_temp[idx] = initvalu[idx] + h * (b31 * finavalu_temp[0][idx] + b32 * finavalu_temp[1][idx]);
        }
    }
}
