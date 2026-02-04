#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

float *initvalu;
float h2_7;
float *initvalu_temp;
float **finavalu_temp;
int i;

#define DATA_SIZE 91
#define LOOP_COUNT 100000

void init_vars() {
    // Allocate input arrays
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));
    finavalu_temp = (float**)malloc(sizeof(float*));
    finavalu_temp[0] = (float*)calloc(DATA_SIZE, sizeof(float));

    // Initialize input values to non-zero to simulate realistic data
    h2_7 = 0.5f;
    for (int j = 0; j < DATA_SIZE; j++) {
        initvalu[j] = (float)(j % 100) * 0.1f;
        finavalu_temp[0][j] = (float)((j + 10) % 80) * 0.05f;
    }
}