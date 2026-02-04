#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float *initvalu;
float b13_1 = 0.1f;
float b13_4 = 0.2f;
float b13_5 = 0.15f;
float b13_6 = 0.12f;
float b13_7 = 0.18f;
float b13_8 = 0.25f;
float b13_9 = 0.3f;
float b13_10 = 0.05f;

float *initvalu_temp;
float **finavalu_temp;

int i;

#define ARRAY_SIZE 91
#define NUM_ROWS 12

void init_vars() {
    initvalu = (float*)calloc(ARRAY_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(ARRAY_SIZE, sizeof(float));

    finavalu_temp = (float**)calloc(NUM_ROWS, sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(ARRAY_SIZE, sizeof(float));
        for (int col = 0; col < ARRAY_SIZE; col++) {
            finavalu_temp[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }

    h = 0.01f;
    b13_1 = 0.1f;
    b13_4 = 0.2f;
    b13_5 = 0.15f;
    b13_6 = 0.12f;
    b13_7 = 0.18f;
    b13_8 = 0.25f;
    b13_9 = 0.3f;
    b13_10 = 0.05f;
}