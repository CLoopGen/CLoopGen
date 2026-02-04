#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float alpha;
float *B;
int ldb;
int i;
int j;
int n1;
int n2;

void init_vars() {
    // Set alpha to a non-trivial value
    alpha = 1.5f;
    
    // Target approximately 64MB of data to ensure loop runs ~0.01 seconds
    // Each float is 4 bytes, so 64MB / 4 = 16M elements
    // Use n1 = 4096, n2 = 4096 -> ~16.7M elements
    n1 = 4096;
    n2 = 4096;
    
    // Set leading dimension to n2 (row-major layout)
    ldb = n2;
    
    // Allocate B as a 2D array with dimensions n1 x n2
    B = (float*)aligned_alloc(32, n1 * n2 * sizeof(float));
    
    // Initialize B with non-zero values to make scaling observable
    for (int idx = 0; idx < n1 * n2; idx++) {
        B[idx] = (float)(idx % 1000) / 100.0f;
    }
}