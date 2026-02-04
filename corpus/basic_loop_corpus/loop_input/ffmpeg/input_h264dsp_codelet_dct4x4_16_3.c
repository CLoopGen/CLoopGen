#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;
int16_t tmp[16];

void init_vars() {
    coef = (int16_t*)aligned_alloc(32, 256 * 1024 * 1024);
    if (!coef) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < (256 * 1024 * 1024) / sizeof(int16_t); j++) {
        coef[j] = (int16_t)(j % 32768);
    }

    for (int j = 0; j < 16; j++) {
        tmp[j] = (int16_t)(j * 100);
    }
}