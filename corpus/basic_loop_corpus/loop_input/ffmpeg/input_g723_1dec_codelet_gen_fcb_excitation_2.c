#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *vector;
int i;
int beta;
int lag;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of int16_t data (~134 million elements)
    vector = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    
    if (!vector) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        vector[idx] = (int16_t)(rand() % 65536 - 32768);
    }

    beta = rand() % 65536 - 32768;
    lag = 1024;
}