#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float h = 0.01f;
float b91 = 0.1f;
float b94 = 0.2f;
float b95 = 0.3f;
float b96 = 0.4f;
float b97 = 0.5f;
float b98 = 0.6f;

#define DATA_SIZE 91
#define NUM_ROWS 8

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 100) / 10.0f;
        initvalu_temp[idx] = 0.0f;
    }

    // Allocate finavalu_temp as an array of float pointers
    finavalu_temp = (float**)aligned_alloc(32, NUM_ROWS * sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(row * col % 50) / 25.0f;
        }
    }
}