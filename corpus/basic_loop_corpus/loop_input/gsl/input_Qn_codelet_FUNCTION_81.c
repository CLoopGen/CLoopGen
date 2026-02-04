#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni = 10000000; // 10M elements for ~0.01 sec runtime

int *left;
int *right;
int *weight;
int i;
int j;
int jh;

void init_vars() {
    // Seed random number generator for predictable but realistic data
    srand(42);
    
    // Allocate arrays
    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));
    weight = (int*)malloc(ni * sizeof(int));
    
    if (!left || !right || !weight) {
        // In case of allocation failure, ensure program can still link and run
        if (!left) left = (int*)calloc(ni, sizeof(int));
        if (!right) right = (int*)calloc(ni, sizeof(int));
        if (!weight) weight = (int*)calloc(ni, sizeof(int));
    }
    
    // Initialize array contents
    for (int idx = 0; idx < ni; ++idx) {
        // Ensure left[i] <= right[i] to trigger the branch in loop
        left[idx] = rand() % 1000;
        right[idx] = left[idx] + (rand() % 500); // so right[i] >= left[i]
    }
    
    // Initialize loop counters
    i = 0;
    j = 0;
    jh = 0;
}