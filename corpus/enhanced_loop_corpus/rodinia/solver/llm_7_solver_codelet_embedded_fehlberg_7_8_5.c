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
    float prev = 0.0f;
    for (i = 0; i < 91; i++) {
        float current_term = h * (b61 * finavalu_temp[0][i] + b64 * finavalu_temp[3][i] + b65 * finavalu_temp[4][i]);
        initvalu_temp[i] = initvalu[i] + current_term + prev;
        prev = current_term;
    }
}
