#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b41;
extern  float b43;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 91; i++) {
            initvalu_temp[i] = initvalu[i] + h * (b41 * finavalu_temp[0][i] + b43 * finavalu_temp[2][i]);
        }
    }
}
