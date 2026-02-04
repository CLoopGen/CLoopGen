#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

float h = 0.01f;
float b81 = 0.25f;
float b85 = 0.15f;
float b86 = 0.35f;
float b87 = 0.25f;
int i;

#define DATA_SIZE 91
#define ROWS 7

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)malloc(DATA_SIZE * sizeof(float));

    // Allocate finavalu_temp as a 2D array with ROWS x DATA_SIZE
    finavalu_temp = (float**)malloc(ROWS * sizeof(float*));
    for (int r = 0; r < ROWS; r++) {
        finavalu_temp[r] = (float*)malloc(DATA_SIZE * sizeof(float));
        for (int c = 0; c < DATA_SIZE; c++) {
            finavalu_temp[r][c] = (float)((r * 100 + c) % 50) / 100.0f;
        }
    }

    // Initialize initvalu with sample data
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 100) / 50.0f;
        initvalu_temp[idx] = 0.0f;
    }
}