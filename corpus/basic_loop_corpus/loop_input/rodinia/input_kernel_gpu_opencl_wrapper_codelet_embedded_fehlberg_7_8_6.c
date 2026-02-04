#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float *initvalu;
float b71 = 0.25f;
float b74 = 0.15f;
float b75 = 0.35f;
float b76 = 0.25f;

float *initvalu_temp;
float **finavalu_temp;
int i;

#define DATA_SIZE 91
#define NUM_ROWS 6

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

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(rand() % 100) / 10.0f;
        initvalu_temp[idx] = 0.0f;
    }
}