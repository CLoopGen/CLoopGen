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
    for (i = 0; i < 91; i++) {
        if (i % 2 == 0) {
            initvalu_temp[i] = initvalu[i] + h * (b31 * finavalu_temp[0][i]);
        } else {
            initvalu_temp[i] = initvalu[i] + h * (b32 * finavalu_temp[1][i]);
        }
    }
}
