#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;

static int16_t *alloc_coef;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of int16_t data
    const size_t num_elements = data_size / sizeof(int16_t);
    
    alloc_coef = (int16_t *)calloc(num_elements, sizeof(int16_t));
    if (!alloc_coef) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    coef = alloc_coef;

    for (size_t idx = 0; idx < num_elements; idx++) {
        alloc_coef[idx] = (int16_t)(idx % 512 - 256); 
    }
}