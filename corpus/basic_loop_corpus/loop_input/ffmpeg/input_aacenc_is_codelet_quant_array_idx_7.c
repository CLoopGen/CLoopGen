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

void init_vars() {
    val = 3.14159f;
    quant_min_err = INFINITY;
    _usr_index = -1;
    num = (1 << 20); // ~4MB of float data (approx 1M elements)

    arr = (float*)aligned_alloc(32, num * sizeof(float));
    if (!arr) {
        exit(1);
    }

    for (int j = 0; j < num; j++) {
        arr[j] = ((float)rand() / RAND_MAX) * 6.28f; // random values around [0, 2*PI]
    }
}