#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float h = 0.01f;
float b61 = 0.25f;
float b64 = 0.35f;
float b65 = 0.40f;
int i;

#define DATA_SIZE 91
#define NUM_ROWS 5

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));

    // Allocate finavalu_temp as array of pointers
    finavalu_temp = (float**)aligned_alloc(32, NUM_ROWS * sizeof(float*));
    
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(row + 1) * 0.1f + (float)(col % 7);
        }
    }

    // Initialize initvalu with sample data
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 10) * 0.5f;
        initvalu_temp[idx] = 0.0f;
    }
}