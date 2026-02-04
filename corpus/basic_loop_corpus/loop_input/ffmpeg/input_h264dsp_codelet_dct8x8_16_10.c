#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int x;
int y;

static int16_t *alloc_coef;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // Aim for ~256MB of data
    const size_t num_elements = data_size / sizeof(int16_t);
    alloc_coef = (int16_t *)calloc(num_elements, sizeof(int16_t));
    if (!alloc_coef) {
        fprintf(stderr, "Failed to allocate coef array\n");
        exit(1);
    }

    coef = alloc_coef;

    for (size_t i = 0; i < num_elements; i++) {
        alloc_coef[i] = (int16_t)(i % 32768);
    }

    x = 0;
    y = 0;
}