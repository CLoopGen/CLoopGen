#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float h = 0.001f;

float *initvalu;
float b61 = 0.5f;
float b64 = 0.25f;
float b65 = 0.75f;
float *initvalu_temp;
float **finavalu_temp;

int i;

#define DATA_SIZE 91
#define NUM_ROWS 5

void init_vars() {
    initvalu = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    finavalu_temp = (float**)aligned_alloc(32, NUM_ROWS * sizeof(float*));

    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }

    for (int i = 0; i < DATA_SIZE; i++) {
        initvalu[i] = (float)(rand() % 100) / 10.0f;
        initvalu_temp[i] = 0.0f;
    }
}