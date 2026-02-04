#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float val;
float *arr;
int num;
int i;
int _usr_index;
float quant_min_err;

void init_vars() {
    val = 3.14159f;
    num = ARRAY_SIZE;
    quant_min_err = INFINITY;
    _usr_index = -1;

    arr = (float*)aligned_alloc(32, num * sizeof(float));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int idx = 0; idx < num; idx++) {
        arr[idx] = ((float)rand() / RAND_MAX) * 6.0f;
    }
}