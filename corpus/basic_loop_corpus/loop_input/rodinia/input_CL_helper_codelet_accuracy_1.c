#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB of data for sufficient runtime

float *arr1;
float *arr2;
int len;
float err;
int i;

void init_vars() {
    // Set length based on data size: each array holds float values
    len = DATA_SIZE / sizeof(float);
    
    // Allocate memory for arr1 and arr2
    arr1 = (float*)aligned_alloc(32, len * sizeof(float));
    arr2 = (float*)aligned_alloc(32, len * sizeof(float));
    
    // Initialize error accumulator
    err = 0.0f;
    i = 0;
    
    // Seed random number generator and initialize arrays
    srand((unsigned int)(time(NULL)));
    for (int j = 0; j < len; j++) {
        arr1[j] = (float)((double)rand() / RAND_MAX * 2.0 - 1.0); // Random in [-1, 1]
        arr2[j] = (float)((double)rand() / RAND_MAX * 2.0 - 1.0); // Random in [-1, 1]
    }
}