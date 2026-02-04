#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float b10_1 = 0.1f;
float b10_4 = 0.2f;
float b10_5 = 0.15f;
float b10_6 = 0.12f;
float b10_7 = 0.08f;
float b10_8 = 0.05f;
float b10_9 = 0.03f;

int i;

#define DATA_SIZE 91

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    initvalu = (float*)calloc(DATA_SIZE, sizeof(float));
    initvalu_temp = (float*)calloc(DATA_SIZE, sizeof(float));

    finavalu_temp = (float**)calloc(9, sizeof(float*));
    for (int row = 0; row < 9; row++) {
        finavalu_temp[row] = (float*)calloc(DATA_SIZE, sizeof(float));
        for (int col = 0; col < DATA_SIZE; col++) {
            finavalu_temp[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(rand() % 100) / 10.0f;
    }
}