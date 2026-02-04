#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
int *crow;
int *ccol;
int pair_counter;
int x_result_len;
double *GICOV_spots;
double *G;
double *x_result;
double *y_result;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime
    // Empirical testing suggests ~4M elements gives desired timing
    pair_counter = 4000000;
    
    // Allocate arrays
    crow = (int*)malloc(pair_counter * sizeof(int));
    ccol = (int*)malloc(pair_counter * sizeof(int));
    GICOV_spots = (double*)malloc(pair_counter * sizeof(double));
    
    // x_result_len will be filled during loop, so pre-estimate worst-case size
    x_result_len = 0;
    x_result = (double*)malloc(pair_counter * sizeof(double));
    y_result = (double*)malloc(pair_counter * sizeof(double));
    G = (double*)malloc(pair_counter * sizeof(double));
    
    // Initialize crow and ccol with values that partially satisfy the condition
    // Condition: (crow[i] > 29) && (crow[i] < 328 - 110 + 39) => (30 <= crow[i] <= 256)
    srand(42);
    for (int idx = 0; idx < pair_counter; idx++) {
        // Randomly assign values to trigger the condition about half the time
        if (rand() % 2 == 0) {
            crow[idx] = 30 + rand() % (257 - 30);  // Within valid range
        } else {
            crow[idx] = rand() % 500;  // Some outside range
        }
        ccol[idx] = rand() % 1000;
        GICOV_spots[idx] = (double)(rand()) / RAND_MAX * 100.0;
    }
}