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
    for (i = 0; i < 91; i += 3) {
        for (int k = 0; k < 3 && (i + k) < 91; k++) {
            initvalu_temp[i + k] = initvalu[i + k] + h * (b41 * finavalu_temp[0][i + k] + b43 * finavalu_temp[2][i + k]);
        }
    }
}
