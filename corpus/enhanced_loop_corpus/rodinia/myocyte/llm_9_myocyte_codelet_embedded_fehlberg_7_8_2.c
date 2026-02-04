#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float h2_7;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 45; i++) {
    float val1 = finavalu_temp[0][i];
    float val2 = finavalu_temp[0][90 - i];
    initvalu_temp[i] = initvalu[i] + h2_7 * val1 + h2_7 * val1 * 0.1f;
    initvalu_temp[90 - i] = initvalu[90 - i] + h2_7 * val2 - h2_7 * val2 * 0.1f;
}
}
