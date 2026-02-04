#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

float h = 0.01f;

float *initvalu;
float b13_1 = 0.1f;
float b13_4 = 0.2f;
float b13_5 = 0.3f;
float b13_6 = 0.4f;
float b13_7 = 0.5f;
float b13_8 = 0.6f;
float b13_9 = 0.7f;
float b13_10 = 0.8f;

float *initvalu_temp;
float **finavalu_temp;

int i;

#define N 91
#define NUM_ROWS 12

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of base data
    const size_t element_size = sizeof(float);
    const size_t total_elements = data_size / element_size;
    
    // Ensure we have enough elements to cover at least N (91) per row
    size_t elements_per_row = N > (data_size / element_size) ? N : (data_size / element_size);
    
    initvalu = (float*)calloc(elements_per_row, sizeof(float));
    initvalu_temp = (float*)calloc(elements_per_row, sizeof(float));
    
    finavalu_temp = (float**)calloc(NUM_ROWS, sizeof(float*));
    for (int row = 0; row < NUM_ROWS; row++) {
        finavalu_temp[row] = (float*)calloc(elements_per_row, sizeof(float));
        for (int col = 0; col < elements_per_row; col++) {
            finavalu_temp[row][col] = (float)(rand() % 100) / 10.0f;
        }
    }
    
    for (int i = 0; i < elements_per_row; i++) {
        initvalu[i] = (float)(rand() % 100) / 10.0f;
    }
}