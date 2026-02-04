#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b91;
extern  float b94;
extern  float b95;
extern  float b96;
extern  float b97;
extern  float b98;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    for (i = 0; i < 45; i += 2) {
        float term1 = finavalu_temp[0][i] + finavalu_temp[3][i];
        float term2 = finavalu_temp[4][i] + finavalu_temp[5][i];
        float term3 = finavalu_temp[6][i] + finavalu_temp[7][i];
        float combined = b91 * term1 + b94 * term2 + b95 * term2 + b96 * term3 + b97 * term3 + b98 * term1;
        initvalu_temp[i] = initvalu[i] + h * combined;
        if (i + 1 < 45) {
            float term1_next = finavalu_temp[0][i+1] + finavalu_temp[3][i+1];
            float term2_next = finavalu_temp[4][i+1] + finavalu_temp[5][i+1];
            float term3_next = finavalu_temp[6][i+1] + finavalu_temp[7][i+1];
            float combined_next = b91 * term1_next + b94 * term2_next + b95 * term2_next + b96 * term3_next + b97 * term3_next + b98 * term1_next;
            initvalu_temp[i+1] = initvalu[i+1] + h * combined_next;
        }
    }
}
