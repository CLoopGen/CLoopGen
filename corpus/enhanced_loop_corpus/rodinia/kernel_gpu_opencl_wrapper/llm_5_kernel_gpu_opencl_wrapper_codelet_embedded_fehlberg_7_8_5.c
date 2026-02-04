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
        float temp_sum = 0.0f;
        if (i >= 10 && i <= 80) {
            temp_sum += b61 * finavalu_temp[0][i];
        }
        if (i < 50) {
            temp_sum += b64 * finavalu_temp[3][i];
        }
        if (i > 30) {
            temp_sum += b65 * finavalu_temp[4][i];
        }
        initvalu_temp[i] = initvalu[i] + h * temp_sum;
    }
}
