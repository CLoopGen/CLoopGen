#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;

float b10_1 = 1.0f;
float b10_4 = 0.5f;
float b10_5 = 0.3f;
float b10_6 = 0.2f;
float b10_7 = 0.4f;
float b10_8 = 0.6f;
float b10_9 = 0.7f;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

int i;

#define DATA_SIZE 91
#define NUM_ROWS 9

void init_vars() {
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));

    finavalu_temp = (float**)calloc(NUM_ROWS, sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(DATA_SIZE, sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(row + 1) * (col % 10 + 1);
        }
    }

    h = 0.01f;
    b10_1 = 1.0f;
    b10_4 = 0.5f;
    b10_5 = 0.3f;
    b10_6 = 0.2f;
    b10_7 = 0.4f;
    b10_8 = 0.6f;
    b10_9 = 0.7f;

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 50 + 1);
    }
}