#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define index _usr_index

float val;
float *arr;
int num;
int i;
int _usr_index;
float quant_min_err;

void init_vars() {
    num = 64 * 1024 * 1024; // ~256MB of float data (64M elements)
    arr = (float*)aligned_alloc(32, num * sizeof(float));
    if (!arr) {
        exit(1);
    }

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((unsigned int)ts.tv_nsec);

    for (int j = 0; j < num; j++) {
        arr[j] = ((float)rand() / RAND_MAX) * 20.0f - 10.0f; // Range [-10, 10]
    }

    val = 5.0f;
    quant_min_err = INFINITY;
    _usr_index = -1;
}