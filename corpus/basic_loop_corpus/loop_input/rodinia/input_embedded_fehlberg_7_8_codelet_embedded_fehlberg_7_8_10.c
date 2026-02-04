#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

float h = 0.01f;

float b11_1 = 0.1f;
float b11_4 = 0.2f;
float b11_5 = 0.15f;
float b11_6 = 0.12f;
float b11_7 = 0.08f;
float b11_8 = 0.05f;
float b11_9 = 0.03f;
float b11_10 = 0.02f;

#define ARRAY_SIZE 91
#define STAGES 11

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    initvalu = (float*)calloc(ARRAY_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(ARRAY_SIZE, sizeof(float));
    
    finavalu_temp = (float**)calloc(STAGES, sizeof(float*));
    for (int s = 0; s < STAGES; s++) {
        finavalu_temp[s] = (float*)calloc(ARRAY_SIZE, sizeof(float));
        for (int j = 0; j < ARRAY_SIZE; j++) {
            finavalu_temp[s][j] = (float)(s * 0.1 + j % 7);
        }
    }

    h = 0.01f;
    b11_1 = 0.1f;
    b11_4 = 0.2f;
    b11_5 = 0.15f;
    b11_6 = 0.12f;
    b11_7 = 0.08f;
    b11_8 = 0.05f;
    b11_9 = 0.03f;
    b11_10 = 0.02f;
}