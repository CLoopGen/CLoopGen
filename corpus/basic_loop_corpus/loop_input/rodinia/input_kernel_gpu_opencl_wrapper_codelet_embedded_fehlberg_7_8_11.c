#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

float h = 0.01f;

float b12_1 = 0.1f;
float b12_6 = 0.2f;
float b12_7 = 0.3f;
float b12_8 = 0.4f;
float b12_9 = 0.5f;
float b12_10 = 0.6f;

#define ARRAY_SIZE 91
#define NUM_ROWS 10

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    
    // Allocate finavalu_temp as a 10x91 matrix
    finavalu_temp = (float**)aligned_alloc(32, NUM_ROWS * sizeof(float*));
    
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
        for (int col = 0; col < ARRAY_SIZE; col++) {
            finavalu_temp[row][col] = (float)(row + col % 10) / 10.0f;
        }
    }
    
    // Initialize initvalu with some base values
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        initvalu[idx] = (float)idx / 10.0f;
        initvalu_temp[idx] = 0.0f;
    }
}