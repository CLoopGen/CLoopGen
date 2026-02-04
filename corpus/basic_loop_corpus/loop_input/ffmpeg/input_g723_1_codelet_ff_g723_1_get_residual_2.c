#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *residual;
int16_t *prev_excitation;
int lag;
int offset;
int i;

#define DATA_SIZE (128 << 20)  // 128 MB of data

void init_vars() {
    residual = (int16_t*)aligned_alloc(32, DATA_SIZE);
    prev_excitation = (int16_t*)aligned_alloc(32, DATA_SIZE);

    if (!residual || !prev_excitation) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(int16_t); idx++) {
        residual[idx] = rand() % 32767;
        prev_excitation[idx] = rand() % 32767;
    }

    lag = 40;
    offset = 10;
}