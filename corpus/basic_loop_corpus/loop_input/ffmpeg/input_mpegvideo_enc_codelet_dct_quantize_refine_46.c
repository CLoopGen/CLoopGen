#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *weight;
int i;
int sum;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of int16_t data (524,288 elements)
    weight = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    if (!weight) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        weight[idx] = (int16_t)(rand() % 100 - 50); // Random values between -50 and 49
    }
    i = 0;
    sum = 0;
}