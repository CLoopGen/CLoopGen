#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coef;
int i;
int32_t tmp[16];

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // ~64MB of int32_t data to target ~0.01 sec runtime
    coef = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    
    if (!coef) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < data_size; j++) {
        coef[j] = (int32_t)(j % 256 - 128);
    }

    i = 0;

    for (int j = 0; j < 16; j++) {
        tmp[j] = 0;
    }
}