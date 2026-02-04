#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *Y;
int incY;
int i;
int iy;

static float *Y_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB of float data
    Y_data = (float *)aligned_alloc(32, data_size);
    
    if (!Y_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        Y_data[idx] = 1.0f;
    }

    N = (data_size / sizeof(float)) / (2 * 1 + 1); // Ensure we write pairs with stride
    incY = 1;
    iy = 0;
    Y = Y_data;
}