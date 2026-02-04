#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 64
#define DATA_SIZE (1 << 20) // ~1MB of data for timing

int16_t cos_tbl[ARRAY_SIZE];
int16_t cos_derivative_tbl[ARRAY_SIZE];
int16_t *lsf;
int16_t *lsp;
int order;
int16_t diff;
int16_t freq;
int32_t tmp;
int i;
int k;

void init_vars() {
    // Initialize array size based on performance target
    lsf = (int16_t*)malloc(DATA_SIZE);
    lsp = (int16_t*)malloc(DATA_SIZE);

    // Ensure order does not exceed safe bounds for arrays and allocated memory
    order = DATA_SIZE / sizeof(int16_t);
    if (order > ARRAY_SIZE) order = ARRAY_SIZE;

    // Initialize cos_tbl and cos_derivative_tbl with dummy values
    for (i = 0; i < ARRAY_SIZE; i++) {
        cos_tbl[i] = (int16_t)((0x7FFF * i) / ARRAY_SIZE);
        cos_derivative_tbl[i] = (int16_t)((0x7FFF * (ARRAY_SIZE - i)) / ARRAY_SIZE);
    }

    // Initialize lsf with non-zero test values to ensure meaningful computation
    for (i = 0; i < order; i++) {
        lsf[i] = (int16_t)((0x7FFF * i) / order);
    }
}