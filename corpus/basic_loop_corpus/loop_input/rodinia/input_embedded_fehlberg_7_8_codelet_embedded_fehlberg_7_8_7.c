#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float *initvalu;
float b81 = 0.25f;
float b85 = 0.35f;
float b86 = 0.15f;
float b87 = 0.25f;

float *initvalu_temp;
float **finavalu_temp;

int i;

#define DATA_SIZE 91
#define NUM_ROWS 7

void init_vars() {
    // Allocate and initialize initvalu
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    for (int i = 0; i < DATA_SIZE; i++) {
        initvalu[i] = (float)(rand() % 100) / 10.0f;
    }

    // Allocate and initialize initvalu_temp
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));

    // Allocate finavalu_temp as a 2D array (NUM_ROWS x DATA_SIZE)
    finavalu_temp = (float**)calloc(NUM_ROWS, sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(DATA_SIZE, sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }
}