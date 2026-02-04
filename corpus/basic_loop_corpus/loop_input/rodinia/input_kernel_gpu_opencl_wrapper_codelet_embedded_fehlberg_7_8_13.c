#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

float h = 0.01f;
float c_1_11 = 0.1f;
float c6 = 0.2f;
float c_7_8 = 0.15f;
float c_9_10 = 0.12f;

#define ARRAY_SIZE 91
#define TEMP_ROWS 11

float *initvalu;
float *finavalu;
float **finavalu_temp;
int i;

void init_vars() {
    // Allocate and initialize initvalu and finavalu
    initvalu = (float*)calloc(ARRAY_SIZE, sizeof(float));
    finavalu = (float*)calloc(ARRAY_SIZE, sizeof(float));
    
    // Initialize with some non-zero values to make computation meaningful
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 100) * 0.5f;
    }
    
    // Allocate and initialize finavalu_temp: 11 rows x 91 columns
    finavalu_temp = (float**)calloc(TEMP_ROWS, sizeof(float*));
    for (int row = 0; row < TEMP_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(ARRAY_SIZE, sizeof(float));
        for (int col = 0; col < ARRAY_SIZE; col++) {
            finavalu_temp[row][col] = (float)((row * 100 + col) % 50) * 0.3f;
        }
    }
}