#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float val;
float *arr;
int num;
int i;
int _usr_index;
float quant_min_err;

#define index _usr_index

void init_vars() {
    num = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    arr = (float*)aligned_alloc(32, num * sizeof(float));
    
    if (!arr) {
        exit(1);
    }

    val = 0.5f;
    quant_min_err = INFINITY;
    index = -1;

    srand(12345);
    for (int j = 0; j < num; j++) {
        arr[j] = ((float)rand() / RAND_MAX) * 2.0f - 0.5f;
    }
}