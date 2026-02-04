#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

float h = 0.001f;

float b10_1 = 0.1f;
float b10_4 = 0.2f;
float b10_5 = 0.15f;
float b10_6 = 0.25f;
float b10_7 = 0.18f;
float b10_8 = 0.22f;
float b10_9 = 0.3f;

#define DATA_SIZE 91
#define STAGES 9

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

int i;

void init_vars() {
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));
    
    finavalu_temp = (float**)calloc(STAGES, sizeof(float*));
    for (int s = 0; s < STAGES; s++) {
        finavalu_temp[s] = (float*)calloc(DATA_SIZE, sizeof(float));
        for (int d = 0; d < DATA_SIZE; d++) {
            finavalu_temp[s][d] = (float)(s * 0.1 + (d % 7)) + 1.0f;
        }
    }
    
    h = 0.001f;
    b10_1 = 0.1f; b10_4 = 0.2f; b10_5 = 0.15f;
    b10_6 = 0.25f; b10_7 = 0.18f; b10_8 = 0.22f; b10_9 = 0.3f;
}