#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float h = 0.01f;

float *initvalu;
float b10_1 = 0.1f;
float b10_4 = 0.2f;
float b10_5 = 0.15f;
float b10_6 = 0.1f;
float b10_7 = 0.1f;
float b10_8 = 0.2f;
float b10_9 = 0.15f;

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
            finavalu_temp[row][col] = (float)(row + 1) * 0.1f;
        }
    }
}