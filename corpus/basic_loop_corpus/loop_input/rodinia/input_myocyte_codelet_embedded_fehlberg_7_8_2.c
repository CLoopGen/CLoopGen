#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

float *initvalu;
float h2_7;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int size = 91;
    const int data_size = 1 << 20; // ~4MB of float data to target desired runtime

    // Allocate and initialize initvalu
    initvalu = (float*)calloc(size, sizeof(float));
    for (int j = 0; j < size; j++) {
        initvalu[j] = 1.0f + (j * 0.1f);
    }

    // Initialize scalar
    h2_7 = 0.5f;

    // Allocate and initialize initvalu_temp
    initvalu_temp = (float*)calloc(size, sizeof(float));

    // Allocate finavalu_temp as pointer to array of 'size' floats
    finavalu_temp = (float**)calloc(1, sizeof(float*));
    finavalu_temp[0] = (float*)calloc(size, sizeof(float));
    for (int j = 0; j < size; j++) {
        finavalu_temp[0][j] = 2.0f + (j * 0.05f);
    }

    // Ensure loop index is reset properly in loop(), no need to set here
}