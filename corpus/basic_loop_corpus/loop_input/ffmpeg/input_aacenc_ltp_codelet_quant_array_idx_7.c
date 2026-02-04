#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define index _usr_index

float val;
float *arr;
int num;
int i;
int _usr_index;
float quant_min_err;

void init_vars() {
    num = 67108864; // Approximately 256MB of float data (67M elements)
    arr = (float*)aligned_alloc(32, num * sizeof(float));
    if (!arr) {
        exit(1);
    }

    for (int j = 0; j < num; j++) {
        arr[j] = (float)(rand() % 1000) / 10.0f;
    }

    val = 42.5f;
    quant_min_err = INFINITY;
    _usr_index = -1;
}