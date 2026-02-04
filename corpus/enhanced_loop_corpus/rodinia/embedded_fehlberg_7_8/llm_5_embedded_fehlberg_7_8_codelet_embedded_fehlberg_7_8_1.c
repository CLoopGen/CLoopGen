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
    for (i = 0; i < 91; i++) {
        float temp_val = finavalu_temp[0][i];
        if (temp_val > 0.0f) {
            initvalu_temp[i] = initvalu[i] + h2_7 * temp_val;
        } else {
            initvalu_temp[i] = initvalu[i];
        }
    }
}
