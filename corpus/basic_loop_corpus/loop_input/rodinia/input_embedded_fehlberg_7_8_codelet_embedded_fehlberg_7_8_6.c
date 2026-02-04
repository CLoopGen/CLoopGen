#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <time.h>

float h = 0.001f;

float b71 = 0.1f;
float b74 = 0.2f;
float b75 = 0.3f;
float b76 = 0.4f;

int i;

#define DATA_SIZE 91
#define NUM_ROWS 6

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)malloc(DATA_SIZE * sizeof(float));
    
    finavalu_temp = (float**)malloc(NUM_ROWS * sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)malloc(DATA_SIZE * sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(row + 1) * (0.1f + col % 7);
        }
    }
    
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)idx * 0.01f;
    }
}