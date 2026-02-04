#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b51;
extern  float b53;
extern  float b54;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i++) {
        float term1 = finavalu_temp[0][i];
        float term2 = finavalu_temp[2][i];
        float term3 = finavalu_temp[3][i];

        if (term1 == 0.0f && term2 == 0.0f && term3 == 0.0f) {
            initvalu_temp[i] = initvalu[i];
            continue;
        }

        initvalu_temp[i] = initvalu[i] + h * (b51 * term1 + b53 * term2 + b54 * term3);
    }
}
