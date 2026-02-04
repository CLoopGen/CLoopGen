#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t gt16x16_cnst[64] __attribute__((aligned(64))) = {0};

int16_t i;
int16_t j;
int16_t k;
int16_t buf[256] __attribute__((aligned(64)));
int16_t *buf_ptr;
int16_t *src;
int16_t *filter;

void init_vars() {
    // Initialize buffer pointers to valid addresses within buf
    buf_ptr = &buf[8];
    src = &buf[0];
    filter = &gt16x16_cnst[0];

    // Initialize gt16x16_cnst with non-zero values to simulate filter coefficients
    for (int idx = 0; idx < 64; idx++) {
        gt16x16_cnst[idx] = (int16_t)(idx - 32);
    }

    // Initialize buf with sample data to prevent undefined behavior
    for (int idx = 0; idx < 256; idx++) {
        buf[idx] = (int16_t)(idx % 512);
    }

    // Initialize loop counters to ensure correct first iteration
    i = 2;
}