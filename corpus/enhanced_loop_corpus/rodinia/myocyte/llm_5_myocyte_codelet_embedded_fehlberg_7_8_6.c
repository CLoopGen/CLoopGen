#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b61;
extern  float b64;
extern  float b65;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i++) {
        float term1 = finavalu_temp[0][i];
        float term2 = finavalu_temp[3][i];
        float term3 = finavalu_temp[4][i];

        if (term1 == 0 && term2 == 0 && term3 == 0) {
            initvalu_temp[i] = initvalu[i];
            continue;
        }

        initvalu_temp[i] = initvalu[i] + h * (b61 * term1 + b64 * term2 + b65 * term3);
    }
}
