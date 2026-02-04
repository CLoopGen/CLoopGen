#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float b51 = 0.25f;
float b53 = 0.5f;
float b54 = 0.75f;

int i;

#define DATA_SIZE 91
#define NUM_ROWS 4

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 100) * 0.5f;
    }

    // Allocate and initialize initvalu_temp
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));

    // Allocate finavalu_temp as a 2D array with NUM_ROWS x DATA_SIZE
    finavalu_temp = (float**)calloc(NUM_ROWS, sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(DATA_SIZE, sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)((row + 1) * (col % 50)) * 0.1f;
        }
    }
}