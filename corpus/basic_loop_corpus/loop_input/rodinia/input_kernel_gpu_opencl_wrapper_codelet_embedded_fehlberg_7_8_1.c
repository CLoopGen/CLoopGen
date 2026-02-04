#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

#define DATA_SIZE 91

float *initvalu;
float h2_7;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    // Allocate and initialize initvalu array
    initvalu = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        initvalu[idx] = (float)(idx % 100) * 0.1f;
    }

    // Initialize scalar value h2_7
    h2_7 = 0.5f;

    // Allocate and initialize initvalu_temp array
    initvalu_temp = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));
    memset(initvalu_temp, 0, DATA_SIZE * sizeof(float));

    // Allocate finavalu_temp as pointer to array of float pointers
    finavalu_temp = (float **)aligned_alloc(32, 1 * sizeof(float *));
    
    // Allocate the first (and only needed) row for finavalu_temp[0]
    finavalu_temp[0] = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        finavalu_temp[0][idx] = (float)((idx + 10) % 80) * 0.2f;
    }
}