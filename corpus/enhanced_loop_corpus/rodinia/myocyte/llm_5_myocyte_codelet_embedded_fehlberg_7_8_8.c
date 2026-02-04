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
    for (i = 0; i < 91; i++) {
        float term1 = finavalu_temp[0][i];
        float term4 = finavalu_temp[4][i];
        float sum = b81 * term1 + b85 * term4;

        if (term1 < 1e-6f && term4 < 1e-6f) {
            initvalu_temp[i] = initvalu[i];
            continue;
        }

        sum += b86 * finavalu_temp[5][i] + b87 * finavalu_temp[6][i];
        initvalu_temp[i] = initvalu[i] + h * sum;
    }
}
